#include "pdf.h"

pdf::pdf()
{
}

pdf::pdf(QString path)
{
    qDebug() << path;
    _absPathToPDF = path;
}

QVector<QString> pdf::convertPDF2Img(QString destPath, QString fNamePrefix, QString imgFormat)
{
    QVector<QString> convertedImgPaths;
    if (!(_absPathToPDF.size() < 1))
    {
        int nP = nPages();
        for (int i = 1; i <= nP; i++)
        {
            _ImageMagickImg.density(Magick::Geometry(300, 300)); // THIS MUST COME BEFORE IMAGE IS READ
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
    }
    return convertedImgPaths;
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

QString pdf::fileName()
// From StackOverflow XDD
{
    std::string base_filename = _absPathToPDF.toStdString().substr(_absPathToPDF.toStdString().find_last_of("/\\") + 1);
    std::string::size_type const p(base_filename.find_last_of('.'));
    std::string file_without_extension = base_filename.substr(0, p);
    return QString::fromStdString(file_without_extension);
}

QString pdf::fileDirectory()
{
    int idx = _absPathToPDF.toStdString().find_last_of("/");
    return QString::fromStdString(_absPathToPDF.toStdString().substr(0, idx));
}
