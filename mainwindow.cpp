#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QtDebug>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::setWindowTitle("Bubble-Sheet-OMR-OpenCV-Qt");
    _selectedPDF = false;
    connect(this, SIGNAL(PDF_Selected(QString)), this, SLOT(handleSelectedPDF(QString)));
    _rubberBand = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ImportPDF_clicked()
{
    ui->progressBar_ConversionDone->setValue(0);
    ui->label_FrameDisplayer->clear();
    QWidget::setWindowTitle("Beta");
    QString absPath2PDF = QFileDialog::getOpenFileName(
                this,
                tr("Choose a PDF"),
                "C:/",
                tr("PDF Files (*.pdf)")
                );
    if (!(absPath2PDF.isEmpty()))
    {
        QWidget::setWindowTitle("[ PDF Read ] " + absPath2PDF);
        emit PDF_Selected(absPath2PDF);
    }
}

void MainWindow::handleSelectedPDF(QString absPath2PDF)
{
    _selectedPDF = true;
    ui->progressBar_ConversionDone->setValue(1);

    QThread* thread = new QThread();
    _doc = new document(absPath2PDF);
    _doc->moveToThread(thread);

    connect(this, SIGNAL(invokePDF2ImgConversion()), _doc, SLOT(convertPDF2Img()));
    connect(&_doc->_PDF, SIGNAL(progressUpdated(double)), this, SLOT(updateProgress(double)));
    connect(_doc, SIGNAL(sheetsReady()), this, SLOT(handleConversionAllDone()));
    connect(&_doc->_PDF, SIGNAL(finishedConversion()), thread, SLOT(quit()));
    thread->start();
    emit invokePDF2ImgConversion();
}

void MainWindow::updateProgress(double lastestProgress)
{
    ui->progressBar_ConversionDone->setValue(int(lastestProgress));
}

void MainWindow::handleConversionAllDone()
{
    updateFrame(_doc->_sheets[0].originalImage());
    ui->label_PageNumber->setNum(1);
}

void MainWindow::updateFrame(QImage frame)
{
    ui->label_FrameDisplayer->setPixmap(QPixmap::fromImage(frame));
}

void MainWindow::on_pushButton_Marking_Generic_clicked()
{
    if (_selectedPDF && _doc->hasConvertedImgs())
    {
        int i;
        for (i = 0; i < _doc->nSheets(); i++)
        {
            _doc->_sheets[i].mark_Generic(0.0, 0.0, 1.0, 1.0);  // x1, y1, x2, y2
        }
        updateFrame(_doc->_sheets[0].markedImage());
    }
}

void MainWindow::on_pushButton_PreviousSheet_clicked()
{
    if (_selectedPDF && _doc->hasConvertedImgs())
    {
        int curPageNo = ui->label_PageNumber->text().toInt();
        if (curPageNo >= 2)
        {
            ui->label_PageNumber->setNum(curPageNo - 1);
            updateFrame(_doc->_sheets[curPageNo - 2].markedImage());
        }
    }
}


void MainWindow::on_pushButton_NextSheet_clicked()
{
    if (_selectedPDF && _doc->hasConvertedImgs())
    {
        int curPageNo = ui->label_PageNumber->text().toInt();
        if (curPageNo < _doc->nSheets())
        {
            ui->label_PageNumber->setNum(curPageNo + 1);
            updateFrame(_doc->_sheets[curPageNo].markedImage());
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
// https://stackoverflow.com/questions/16527248/qrubberband-on-a-definite-label
{
    _lastClickedBtn = event->button();
    if (_lastClickedBtn == Qt::LeftButton)
    {
        _mouseClickPoint = ui->label_FrameDisplayer->mapFromGlobal(this->mapToGlobal(event->pos()));
        if(_rubberBand == nullptr)
            _rubberBand = new QRubberBand(QRubberBand::Rectangle, ui->label_FrameDisplayer);
        _rubberBand->setGeometry(QRect(_mouseClickPoint, _mouseClickPoint));
        _rubberBand->show();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(_rubberBand != nullptr)
    {
        if (_lastClickedBtn == Qt::LeftButton)
        {
            QPoint mouseCurrentPoint = ui->label_FrameDisplayer->mapFromGlobal(this->mapToGlobal(event->pos()));
            _rubberBand->setGeometry(QRect(_mouseClickPoint, mouseCurrentPoint).normalized());
            qDebug() << _rubberBand->size();
        }
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(_rubberBand != nullptr)
    {
        _rubberBand->hide();
        _rubberBand->clearMask();
    }
}
