#include "mainwindow.h"
#include <QApplication>

#include <Magick++.h>

int main(int argc, char *argv[])
{
    Magick::InitializeMagick(*argv);    // Put DLLs at runtime DIR
    QApplication a(argc, argv);
    qRegisterMetaType<std::string>("std::string");
    qRegisterMetaType<std::vector<std::string>>("std::vector<std::string>");
    MainWindow w;
    w.show();

    return a.exec();
}
