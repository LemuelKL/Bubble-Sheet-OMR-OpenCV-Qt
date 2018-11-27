#include "cv_worker.h"

#include <QDebug>
#include <QThread>

// --- CONSTRUCTOR ---
cv_worker::cv_worker(QStringList paths) {
    // you could copy data from constructor arguments to internal variables here.
    mImgPaths = paths;
    mNPages = mImgPaths.size();
}

// --- DECONSTRUCTOR ---
cv_worker::~cv_worker() {
    // free resources
}

// --- PROCESS ---
// Start processing data.
void cv_worker::process() {
    // allocate resources using new here
    qDebug("CV WORKER STARTED");
    qDebug()<<QThread::currentThread();

    int i;
    for (i=0;i<mNPages;i++)
    {
        mDoc.push_back(cv::imread(mImgPaths[i].toStdString(), -1));
    }

    for(cv::Mat& img : mDoc)
    {
        cv::Mat grayImg;
        cv::cvtColor(img, grayImg, cv::COLOR_BGR2GRAY);
        //emit sendImg(grayImg);

        std::vector<std::vector<cv::Point> > contours;
        std::vector<cv::Vec4i> hierarchy;
        cv::findContours(grayImg.clone(), contours, hierarchy, cv::RETR_CCOMP, cv::CHAIN_APPROX_NONE);
        cv::drawContours(img, contours, -1, cv::Scalar(0,255,0), 1);
        emit sendImg(img);

    }



    emit finished();
}
