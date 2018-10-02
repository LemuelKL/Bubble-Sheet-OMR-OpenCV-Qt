#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <stdio.h>
#include <iostream>
#include <string>

#include <pdf.h>

#include <QDir>
#include <QFileDialog>
#include <QMessageBox>

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
    //pdf sheet("D:\\Users\\Lemuel\\Desktop\\test.pdf");


     // CARE

    Image pdf;

    pdf.density(Geometry(300,300)); // THIS MUST COME BEFORE IMAGE IS READ
    pdf.read("pdf/3.pdf");
    pdf.quality(100);
    pdf.write("pdf/3.png");

    Mat img;
    img = imread("pdf/3.png", -1);


    ui->label_displayImg->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, int(img.step), QImage::Format_RGB888)));
    ui->label_displayImg->setScaledContents( true );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void singleImgAlgorithm(std::string)
{
    // //
}

void MainWindow::on_pushButton_Choose_PDF_clicked()
{
    QString path2Pdf = QFileDialog::getOpenFileName(
                this,
                tr("Choose PDF"),
                "C:/",
                tr("PDF Files (*.pdf)")
                );
    if (path2Pdf.isEmpty()){
        QMessageBox::warning(this, tr("What are you doing?"), tr("Please select a PDF file."));
    }

    pdf p(path2Pdf.toStdString());
    p.ConvertToPNGs("D:/Users/Lemuel/Software-Development/Bubble-Sheet-OMR/Bubble-Sheet-OMR-OpenCV-Qt/pdf", "AAA");
    //QMessageBox::information(this, tr("a"), QString::number(p.));
}
