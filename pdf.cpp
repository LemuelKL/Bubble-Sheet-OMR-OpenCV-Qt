#include "pdf.h"

pdf::pdf(std::string fullPath)
{
    mFullPath = fullPath;
}
std::string pdf::FullPath()
{
    return mFullPath;
}
int pdf::fetchNPages()
{
    MagickCore::MagickWand *m_wand = nullptr;
    MagickCore::MagickWandGenesis();
    m_wand = MagickCore::NewMagickWand();
    MagickCore::MagickReadImage(m_wand, mFullPath.c_str());
    int nPage = int(MagickCore::MagickGetNumberImages(m_wand));
    return nPage;
}
void pdf::ConvertToPNGs(std::string destPath, std::string namePrefix)
{
    int i;
    for (i=1; i<=fetchNPages(); i++)
    {
        mFile.density(Magick::Geometry(300,300)); // THIS MUST COME BEFORE IMAGE IS READ
        mFile.read(mFullPath+"["+std::to_string(i-1)+"]");
        mFile.quality(100);
        mFile.write(destPath+"/"+namePrefix+"-"+std::to_string(i)+".png");
    }
}

