#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <document.h>
#include <QRubberBand>

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

    void handleConversionAllDone();

    void updateFrame(QImage);
    void on_pushButton_Marking_Generic_clicked();

    void on_pushButton_PreviousSheet_clicked();

    void on_pushButton_NextSheet_clicked();

private:
    Ui::MainWindow *ui;

    document* _doc;

    bool _selectedPDF;

    QRubberBand* _rubberBand;
    QPoint _mouseClickPoint;
    Qt::MouseButton _lastClickedBtn;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
};

#endif // MAINWINDOW_H
