#include "document.h"

document::document()
{
}

document::document(QString absPDF) : _PDF(absPDF)
{
}

void document::convertPDF2Img()
{
    QVector<QString> convertedImgPaths = _PDF.convertPDF2Img("D:/Users/Lemuel/Desktop", "testing", ".png");
    int i;
    for (i = 0; i < convertedImgPaths.size(); i++)
    {
        _sheets.push_back(sheet(convertedImgPaths.at(i)));
    }
    emit sheetsReady();
}

bool document::hasConvertedImgs()
{
    if (_sheets.size() > 0)
        return true;
    return false;
}

int document::nSheets()
{
    return _sheets.size();
}
