#ifndef PDF_H
#define PDF_H
#include <QObject>
#include <QElapsedTimer>
#include "mainwindow.h"

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

class pdf : public QObject
{
    Q_OBJECT
private:
    Magick::Image mFile;
    int mnPages;
    int fetchNPages();
    std::string mDestPath;
    std::string mImgFormat;
    std::string mNamePrefix;

public:
    static std::string mFullPath;
    pdf(std::string fullPath);
    void SetFullPath(std::string path);
    std::string FullPath();
    void setArgs(std::string destPath, std::string namePrefix, std::string imgFormat);

public slots:
    void ConvertToImgs();

signals:
    void badImgFormat();
    void startedConverting();
    void progressUpdated(double perc);
    void newlyConverted(std::string convertedImgName);
    void finishedConverting(qint64 timeTook);
};

#endif // PDF_H
