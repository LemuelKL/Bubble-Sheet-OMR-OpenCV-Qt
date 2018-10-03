#ifndef PDF_H
#define PDF_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <string>

#pragma warning(push)
#pragma warning(disable:4251)
#include <Magick++.h>
#include <wand/magick_wand.h>
#pragma warning(pop)


#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

class pdf
{
private:
    Magick::Image mFile;
    int mnPages;
    int fetchNPages();

public:
    static std::string mFullPath;
    pdf(std::string fullPath);
    void SetFullPath(std::string path);
    std::string FullPath();
    std::vector<std::string> ConvertToImgs(std::string destPath, std::string namePrefix, std::string imgFormat);
};

#endif // PDF_H
