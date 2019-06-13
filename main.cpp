#include "mainwindow.h"
#include <QApplication>

#include <asposecpplib/system/shared_ptr.h>

using namespace

int main(int argc, char *argv[])
{

    SharedPtr converter = MakeObject();
    // load an existing PDF document
    converter->BindPdf(dir + L"template.pdf");
    // convert PDF pages to images
    converter->DoConvert();
    int32_t imageCount = 1;
    while (converter->HasNextImage()) {
     // save each page in JPG format
     converter->GetNextImage(dir + imageCount + L".jpg", System::Drawing::Imaging::ImageFormat::get_Jpeg(), 800, 1000);
     imageCount++;
    }





    Magick::InitializeMagick(argv[0]);
/*
    Magick::Image img("1.png");
    img.write("2.png");*/
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
