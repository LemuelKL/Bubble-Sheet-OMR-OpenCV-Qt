#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget::setWindowTitle("Bubble-Sheet-OMR-OpenCV-Qt");
    _isConverting = false;
    _selectedPDF = false;
    connect(this, SIGNAL(PDF_Selected(QString)), this, SLOT(handleSelectedPDF(QString)));

    connect(ui->label_FrameDisplayer, SIGNAL(mouseMoved(int, int)), this, SLOT(updateMouseXY(int, int)));
    connect(ui->label_FrameDisplayer, SIGNAL(mouseLeave()), this, SLOT(blankMouseXY()));

    connect(ui->label_FrameDisplayer, SIGNAL(roiSelectedToMark(QRect)), this, SLOT(markInRoi(QRect)));
    connect(ui->label_FrameDisplayer, SIGNAL(roiSelectedToRemoveMark(QRect)), this, SLOT(removeMarkInRoi(QRect)));

    connect(ui->label_FrameDisplayer, SIGNAL(roiSelectedToMark(QRect)), this, SLOT(updateBubblesData()));
    connect(ui->label_FrameDisplayer, SIGNAL(roiSelectedToRemoveMark(QRect)), this, SLOT(updateBubblesData()));

    ui->tabWidget->setCurrentIndex(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ImportPDF_clicked()
{
    if (!(_isConverting))
    {
        ui->spinBox_Marking_endPage->setMaximum(0);
        ui->spinBox_Marking_endPage->setValue(0);
        ui->spinBox_Grouping_endPage->setMaximum(0);
        ui->spinBox_Grouping_endPage->setValue(0);

        ui->progressBar_ConversionDone->setValue(0);
        ui->label_FrameDisplayer->clear();
        QWidget::setWindowTitle("Bubble-Sheet-OMR-OpenCV-Qt");
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
    connect(&_doc->_PDF, SIGNAL(progressUpdated(double)), this, SLOT(addOneToMaxNoPages()));
    thread->start();
    _isConverting = true;
    emit invokePDF2ImgConversion();
}

void MainWindow::updateProgress(double lastestProgress)
{
    ui->progressBar_ConversionDone->setValue(int(lastestProgress));
}

void MainWindow::addOneToMaxNoPages()
{
    int currentMax = ui->spinBox_Marking_endPage->value();
    ui->spinBox_Marking_endPage->setMinimum(1);
    ui->spinBox_Marking_endPage->setMaximum(currentMax + 1);
    ui->spinBox_Marking_endPage->setValue(currentMax + 1);
    ui->spinBox_Marking_startPage->setMaximum(currentMax + 1);

    ui->spinBox_Grouping_endPage->setMinimum(1);
    ui->spinBox_Grouping_endPage->setMaximum(currentMax + 1);
    ui->spinBox_Grouping_endPage->setValue(currentMax + 1);
    ui->spinBox_Grouping_startPage->setMaximum(currentMax + 1);
}

void MainWindow::handleConversionAllDone()
{
    _isConverting = false;
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
        for (i = ui->spinBox_Marking_startPage->value(); i <= ui->spinBox_Marking_endPage->value(); i++)
        {
            _doc->_sheets[i-1].mark_Generic(0.0, 0.0, 1.0, 1.0, ui->checkBox_ifUniformBubblesShapes->checkState());  // x1, y1, x2, y2
            updateFrame(_doc->_sheets[i-1].markedImage());
        }
        updateFrame(_doc->_sheets[ui->spinBox_Marking_startPage->value() - 1].markedImage());
        ui->label_PageNumber->setNum(ui->spinBox_Marking_startPage->value());
        updateBubblesData();
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
    updateInfo();
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
    updateInfo();
}

void MainWindow::updateMouseXY(int x, int y)
{
    ui->label_xCoordHolder->setNum(x);
    ui->label_yCoordHolder->setNum(y);
}

void MainWindow::blankMouseXY()
{
    ui->label_xCoordHolder->setText(" ");
    ui->label_yCoordHolder->setText(" ");
}

void MainWindow::markInRoi(QRect ROI)
{
    if (_selectedPDF && _doc->hasConvertedImgs())
    {
        QRect fdRect = ui->label_FrameDisplayer->frameRect();
        double relX1 = 1.0 * ROI.x() / fdRect.width();
        double relY1 = 1.0 * ROI.y() / fdRect.height();
        double relX2 = 1.0 * ROI.right() / fdRect.width();
        double relY2 = 1.0 * ROI.bottom() / fdRect.height();

        _doc->_sheets[ui->label_PageNumber->text().toInt()-1].mark_Generic(relX1, relY1, relX2, relY2, ui->checkBox_ifUniformBubblesShapes->checkState());  // x1, y1, x2, y2
        updateFrame(_doc->_sheets[ui->label_PageNumber->text().toInt()-1].markedImage());
    }
}
void MainWindow::removeMarkInRoi(QRect ROI)
{
    if (_selectedPDF && _doc->hasConvertedImgs())
    {
        QRect fdRect = ui->label_FrameDisplayer->frameRect();
        double relX1 = 1.0 * ROI.x() / fdRect.width();
        double relY1 = 1.0 * ROI.y() / fdRect.height();
        double relX2 = 1.0 * ROI.right() / fdRect.width();
        double relY2 = 1.0 * ROI.bottom() / fdRect.height();

        _doc->_sheets[ui->label_PageNumber->text().toInt()-1].unmarkInRoi(relX1, relY1, relX2, relY2);  // x1, y1, x2, y2
        updateFrame(_doc->_sheets[ui->label_PageNumber->text().toInt()-1].markedImage());
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    ui->label_FrameDisplayer->setMode(index);
}

void MainWindow::on_pushButton_GroupBubbles_clicked()
{
    if (_selectedPDF && _doc->hasConvertedImgs())
    {
        if (ui->comboBox_GroupingMethod->currentIndex() == 0)
        {
            qDebug() << "Trying to call Generic Grouping Method";
            _doc->groupBubbles_GenericMethod(ui->spinBox_Grouping_startPage->value(), ui->spinBox_Grouping_endPage->value());
        }
        if (ui->comboBox_GroupingMethod->currentIndex() == 1)
        {
            qDebug() << "Trying to call K-Mean Clustering Method";
            _doc->groupBubbles_kMeanClustering(ui->spinBox_Grouping_startPage->value(),
                                               ui->spinBox_Grouping_endPage->value() - ui->spinBox_Grouping_startPage->value() + 1,
                                               ui->spinbox_CurrentPage_nQuestions->value());
        }
    }
}

void MainWindow::updateBubblesData()
{
    this->_doc->loadSheetsCtnsToBubbles();
    ui->label_Holder_Overall_nBubbles->setText(QString::number(_doc->nBubbles()));
}

void MainWindow::updateInfo()
{
    updateCurrentPageInfo();
    updateOverAllInfo();
}

void MainWindow::updateOverAllInfo()
{

    ui->spinBox_OverAll_nQuestions->setValue(_doc->nQuestions());
}

void MainWindow::updateCurrentPageInfo()
{
    ui->spinbox_CurrentPage_nQuestions->setValue(_doc->_sheets[ui->label_PageNumber->text().toInt()-1].nQuestions());
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    if (index == 2)
    {
        if (_selectedPDF && _doc->hasConvertedImgs())
        {
            updateInfo();
        }
    }
}

int MainWindow::currentPageNo()
{
    return ui->label_PageNumber->text().toInt() - 1;
}

void MainWindow::on_spinbox_CurrentPage_nQuestions_valueChanged(const QString &arg1)
{
    _doc->_sheets[currentPageNo()].setNQuestions(arg1.toInt());
    updateInfo();
}
