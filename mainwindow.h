#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "cv_controller.h"
#include "cv_worker.h"

#include <QMainWindow>
#include <QMetaType>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Choose_PDF_clicked();

    void on_pushButton_ConvertPdf2Png_clicked();

    void onProgressUpdated(double perc);

    void onNewlyConverted(std::string convertedImgName);

    void onStartedConverting();

    void onBadImgFormat();

    void onFinishedConverting(qint64 timeTook);

    void onObjDestroyed();

    void recieveImgPaths(std::vector<std::string> ImgPaths);

    void on_pushButton_CV_Worker_clicked();

    void errorString(QString);

    void updateImg(QImage img);

    void updateImgStorage(std::vector<QImage> imgs, int startP, int endP);

    void on_pushButton_PrevPage_clicked();

    void on_pushButton_NextPage_clicked();

    void on_pushButton_AllDone_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<QImage> mDisplayImgs;
    int mNPages;
};

#endif // MAINWINDOW_H
