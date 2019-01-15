#include "pdf.h"

pdf::pdf()
{
}

pdf::pdf(QString path)
{
    _absPathToPDF = path;
}

QVector<QString> pdf::convertPDF2Img(QString destPath, QString fNamePrefix, QString imgFormat)
{
    QVector<QString> convertedImgPaths;
    if (!(_absPathToPDF.size() < 1))
    {
        int i;
        int nP = nPages();
        for (i = 1; i <= nP; i++)
        {
            _ImageMagickImg.density(Magick::Geometry(300,300)); // THIS MUST COME BEFORE IMAGE IS READ
            _ImageMagickImg.read(_absPathToPDF.toStdString() + "[" + std::to_string(i - 1) + "]");
            _ImageMagickImg.quality(100);
            _ImageMagickImg.backgroundColor("white");
            _ImageMagickImg.alphaChannel(Magick::AlphaChannelType::RemoveAlphaChannel);
            _ImageMagickImg.mergeLayers(Magick::FlattenLayer);
            _ImageMagickImg.write(destPath.toStdString() + "/" + fNamePrefix.toStdString() + "-p" + std::to_string(i) + imgFormat.toStdString());
            convertedImgPaths.push_back(destPath + "/" + fNamePrefix + "-p" + QString::fromStdString(std::to_string(i)) + imgFormat);
            emit progressUpdated(100.00 * i / nP);
        }
        emit finishedConversion();
        return convertedImgPaths;
    }
}

int pdf::nPages()
{
    MagickCore::MagickWand *pWand;
    MagickCore::MagickWandGenesis();
    pWand = MagickCore::NewMagickWand();
    MagickCore::MagickReadImage(pWand, _absPathToPDF.toStdString().c_str());
    int nPage = int(MagickCore::MagickGetNumberImages(pWand));
    return nPage;
}
