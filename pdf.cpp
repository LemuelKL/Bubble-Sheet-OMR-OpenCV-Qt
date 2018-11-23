#include "pdf.h"
#include "ui_mainwindow.h"
#include <QDebug>

std::string pdf::mFullPath = "";

pdf::pdf(std::string fullPath)
{
    mFullPath = fullPath;
}
void pdf::SetFullPath(std::string fullPath)
{
    mFullPath = fullPath;
}
std::string pdf::FullPath()
{
    return mFullPath;
}
int pdf::fetchNPages()
{
    MagickCore::MagickWand *m_wand;
    MagickCore::MagickWandGenesis();
    m_wand = MagickCore::NewMagickWand();
    MagickCore::MagickReadImage(m_wand, mFullPath.c_str());
    int nPage = int(MagickCore::MagickGetNumberImages(m_wand));
    return nPage;
}
void pdf::setArgs(std::string destPath, std::string namePrefix, std::string imgFormat)
{
    mDestPath = destPath;
    mImgFormat = imgFormat;
    mNamePrefix = namePrefix;
}
void pdf::ConvertToImgs()
{
    std::vector<std::string> convertedImgNames;
    std::string convertedImgName;
    if (mImgFormat.empty()==true || (mImgFormat!=".jpg" && mImgFormat!=".png" && mImgFormat!= ".bmp"))
    {
        emit badImgFormat();
    }
    else
    {
        QElapsedTimer timer;
        timer.start();
        emit startedConverting();
        int i;
        int nPages = fetchNPages();
        double percDone = 0;
        for (i=1; i<=nPages; i++)
        {
            mFile.density(Magick::Geometry(300,300)); // THIS MUST COME BEFORE IMAGE IS READ
            mFile.read(mFullPath+"["+std::to_string(i-1)+"]");
            mFile.quality(100);
            mFile.backgroundColor("white");
            mFile.alphaChannel(Magick::AlphaChannelType::RemoveAlphaChannel);
            mFile.mergeLayers(Magick::FlattenLayer);
            mFile.write(mDestPath+"/"+mNamePrefix+"-"+std::to_string(i)+mImgFormat);
            convertedImgName = mDestPath+"/"+mNamePrefix+"-"+std::to_string(i)+mImgFormat;
            percDone = 100.00*i/nPages;
            emit progressUpdated(percDone);
            emit newlyConverted(convertedImgName);
            convertedImgNames.push_back(convertedImgName);
        }
        emit sendImgPaths(convertedImgNames);
        emit finishedConverting(timer.elapsed());
    }
}


