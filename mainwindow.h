#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
