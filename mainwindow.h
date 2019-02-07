#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <document.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void PDF_Selected(QString);

    void invokePDF2ImgConversion();

private slots:
    void on_pushButton_ImportPDF_clicked();

    void handleSelectedPDF(QString);

    void updateProgress(double);

    void addOneToMaxNoPages();

    void handleConversionAllDone();

    void updateFrame(QImage);

    void on_pushButton_Marking_Generic_clicked();

    void on_pushButton_PreviousSheet_clicked();

    void on_pushButton_NextSheet_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_pushButton_GroupBubbles_clicked();

public slots:
    void updateMouseXY(int ,int);
    void blankMouseXY();

    void markInRoi(QRect);
    void removeMarkInRoi(QRect);

    void updateBubblesData();

private:
    Ui::MainWindow *ui;

    document* _doc;

    bool _isConverting;
    bool _selectedPDF;
};

#endif // MAINWINDOW_H
