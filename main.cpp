#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Magick::InitializeMagick("C:/Program Files/ImageMagick-6.9.10-Q16");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
