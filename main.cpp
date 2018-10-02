#include "mainwindow.h"
#include <QApplication>

#include <Magick++.h>

int main(int argc, char *argv[])
{
    Magick::InitializeMagick(*argv);    // Put DLLs at runtime DIR
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
