#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>

#include <stdio.h>
#include <iostream>
#include <string>

#include <pdf.h>

#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QThread>

#include <Magick++.h>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace Magick;
using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Bubble Sheet Optical Mark Recognition");

    qRegisterMetaType< cv::Mat >("cv::Mat");
    qRegisterMetaType< std::vector<QImage> >("std::vector<QImage>");

    ui->progressBar_Pdf2Img->setMaximum(100);
    ui->progressBar_Pdf2Img->setMinimum(0);
    ui->progressBar_Pdf2Img->setValue(0);

    ui->textBrowser_Console->setText("...");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Choose_PDF_clicked()
{
    ui->progressBar_Pdf2Img->setValue(0);
    QString path2Pdf = QFileDialog::getOpenFileName(
                this,
                tr("Choose PDF"),
                "C:/",
                tr("PDF Files (*.pdf)")
                );
    if (path2Pdf.isEmpty()){
        QMessageBox::warning(this, tr("What are you doing?"), tr("Please select a PDF file."));
    }
    else
    {
        pdf::mFullPath = path2Pdf.toStdString();
        ui->textBrowser_Console->setText(("[ PDF Read ] "+pdf::mFullPath).c_str());
    }
}

void MainWindow::onProgressUpdated(double perc)
{
    ui->progressBar_Pdf2Img->setValue(int(perc));
}
void MainWindow::onNewlyConverted(std::string convertedImgName)
{
    convertedImgName = "[ PDF -> Image ] "+convertedImgName;
    QString str = QString::fromUtf8(convertedImgName.c_str());
    ui->textBrowser_Console->append(str);
}
void MainWindow::onStartedConverting()
{
    QString str = QString::fromUtf8("[ PDF -> Image Conversion Started ] ");
    ui->textBrowser_Console->append(str);
}
void MainWindow::onBadImgFormat()
{
    QMessageBox::warning(this, tr("What the heck?"),  tr("Bad Target Image Format!"));
}
void MainWindow::onFinishedConverting(qint64 timeTook)
{
    QString str = QString("[ PDF -> Image Conversion Finished After " + QString::number(timeTook/1000) + " Seconds ] ");
    ui->textBrowser_Console->append(str);
}
void MainWindow::onObjDestroyed()
{
    QMessageBox::information(this, tr("DESTRUCTION"), tr("An pdfFile object has been destroyed!"));
}
void MainWindow::recieveImgPaths(std::vector<std::string> ImgPaths)
{
    int i;
    for (i = 0; i < int(ImgPaths.size()); i++)
    {
        QString str = QString::fromStdString(ImgPaths.at(i).c_str());
        ui->textBrowser_ConvertedImagePaths->append(str);
    }
    //QMessageBox::information(this, tr("Success"), tr(ImgPaths[0].c_str()));
    QMessageBox::information(this, tr("Success"), tr("Done!"));
}
void MainWindow::on_pushButton_ConvertPdf2Png_clicked()
{
    ui->progressBar_Pdf2Img->setValue(0);
    ui->textBrowser_ConvertedImagePaths->clear();
    if (pdf::mFullPath.size()<1)
    {
        QMessageBox::warning(this, tr("What are you doing?"), tr("Please have a PDF file loaded first."));
    }
    else if (ui->lineEdit_SetImgPrefix->text().length()<1)
    {
        QMessageBox::warning(this, tr("What are you doing?"), tr("Please set a desirable prefix for image names."));
    }
    else
    {
        vector<string> ret;

        QThread* thread = new QThread;
        pdf* pdfFile = new pdf(pdf::mFullPath);

        std::string outPath;
        outPath = pdfFile->FullPath().substr(0, pdfFile->FullPath().find_last_of("\\/"));
        pdfFile->setArgs(outPath,
                         ui->lineEdit_SetImgPrefix->text().toStdString(),
                         ui->comboBox_SelectOutImgFormat->currentText().toStdString());

        pdfFile->moveToThread(thread);

        connect(pdfFile, SIGNAL (badImgFormat()), this, SLOT(onBadImgFormat()));
        connect(pdfFile, SIGNAL (startedConverting()), this, SLOT(onStartedConverting()));
        connect(pdfFile, SIGNAL (progressUpdated(double)), this, SLOT(onProgressUpdated(double)));
        connect(pdfFile, SIGNAL (newlyConverted(std::string)), this, SLOT (onNewlyConverted(std::string)));
        connect(pdfFile, SIGNAL (sendImgPaths(std::vector<std::string>)), this, SLOT (recieveImgPaths(std::vector<std::string>)));

        connect(thread, SIGNAL (started()), pdfFile, SLOT (ConvertToImgs()));

        connect(pdfFile, SIGNAL (finishedConverting(qint64)), this, SLOT (onFinishedConverting(qint64)));
        connect(pdfFile, SIGNAL (finishedConverting(qint64)), thread, SLOT (quit()));
        connect(pdfFile, SIGNAL (finishedConverting(qint64)), pdfFile, SLOT (deleteLater()));
        connect(thread, SIGNAL (finished()), thread, SLOT (deleteLater()));

        //connect(thread, SIGNAL (destroyed()), this, SLOT (onObjDestroyed()));

        thread->start();
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::errorString(QString errStr)
{
    qDebug()<<errStr;
}

void MainWindow::on_pushButton_CV_Worker_clicked()
{
    if (ui->textBrowser_ConvertedImagePaths->toPlainText().length() < 1)
    {
        QMessageBox::warning(this, tr("What the heck?"),  tr("Process PDF first!"));
        return;
    }
    QString ImgPaths = ui->textBrowser_ConvertedImagePaths->toPlainText();
    QStringList lines = ImgPaths.split("\n");
    qDebug()<<QThread::currentThread();

    QThread* thread = new QThread;
    cv_worker* worker = new cv_worker(lines);
    worker->moveToThread(thread);
    connect(worker, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
    connect(thread, SIGNAL(started()), worker, SLOT(process()));
    connect(worker, SIGNAL(finished()), thread, SLOT(quit()));
    connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    connect(worker, SIGNAL(sendImg(QImage)), this, SLOT(updateImg(QImage)));
    connect(worker, SIGNAL(transportImgs(std::vector<QImage>)), this, SLOT(updateImgStorage(std::vector<QImage>)));

    thread->start();
}

void MainWindow::updateImg(QImage img)
{
    ui->label_displayImg->setPixmap(QPixmap::fromImage(img));
    ui->label_displayImg->setScaledContents(true);
}

void MainWindow::updateImgStorage(std::vector<QImage> img)
{
    mDisplayImgs = img;
    mNPages = int(mDisplayImgs.size());
    updateImg(mDisplayImgs.at(1-1));
    ui->label_CurrentPageNumber->setText("1");
}

void MainWindow::on_pushButton_PrevPage_clicked()
{
    if (!(mDisplayImgs.size() == 0))
    {
        QString cpn = ui->label_CurrentPageNumber->text();
        int int_cpn = cpn.toInt();
        if (int_cpn<2)
        {
            return;
        }
        int_cpn -= 1;
        updateImg(mDisplayImgs.at(int_cpn-1));
        cpn = QString::number(int_cpn);
        ui->label_CurrentPageNumber->setText(cpn);
    }
}

void MainWindow::on_pushButton_NextPage_clicked()
{
    if (!(mDisplayImgs.size() == 0))
    {
        QString cpn = ui->label_CurrentPageNumber->text();
        int int_cpn = cpn.toInt();
        if (int_cpn>mNPages-1)
        {
            return;
        }
        int_cpn += 1;
        updateImg(mDisplayImgs.at(int_cpn-1));
        cpn = QString::number(int_cpn);
        ui->label_CurrentPageNumber->setText(cpn);
    }
}
