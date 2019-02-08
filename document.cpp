#include "document.h"

document::document()
{
}

document::document(QString absPDF) : _PDF(absPDF)
{
}

void document::convertPDF2Img()
{
    QString prefix = _PDF.fileName();
    QString dir = _PDF.fileDirectory();
    QVector<QString> convertedImgPaths = _PDF.convertPDF2Img(dir, prefix, ".png");
    int i;
    for (i = 0; i < convertedImgPaths.size(); i++)
    {
        _sheets.push_back(sheet(convertedImgPaths.at(i)));
    }
    emit sheetsReady();
}

bool document::hasConvertedImgs()
{
    return !(_sheets.empty());
}

int document::nSheets()
{
    if (_sheets.empty())
        return 0;
    return _sheets.size();
}

int document::nBubbles()
{
    int n = 0;
    for (int i = 0; i < nSheets(); i++)
    {
        n = n + _sheets[i].nBubbles();
    }
    return n;
}

void document::loadSheetsCtnsToBubbles()
{
    for (int i = 0; i < nSheets(); i++)
    {
        _sheets[i].loadCtnsToBubbles();
    }
}

void document::groupBubbles_kMeanClustering(int startPage, int nPages, int k)
{
    int page = startPage - 1;
    while (nPages > 0)
    {
        _sheets[page].groupBubbles_kMeanClustering(k);
        page++;
        nPages--;
    }
}

int document::nQuestions()
{
    int n = 0;
    for (int i = 0; i < nSheets(); i++)
    {
        n = n + _sheets[i].nQuestions();
    }
    return n;
}
