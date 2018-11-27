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

    for(cv::Mat& rawImg : mDoc)
    {
        cv::Mat grayImg;
        cv::cvtColor(rawImg, grayImg, cv::COLOR_BGR2GRAY);
        cv::Mat blurry;
        cv::GaussianBlur(grayImg, blurry, cv::Size(3, 3), 1);
        cv::Mat adapt_thresh;
        cv::adaptiveThreshold(blurry, adapt_thresh, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY_INV, 11, 2);

        cv::Mat img;
        img = adapt_thresh;

        std::vector<std::vector<cv::Point> > circleContours;
        circleContours = findCircleContours(img);
        cv::drawContours(rawImg, circleContours, -1, cv::Scalar(0,0,255), 2);
        emit sendImg(rawImg);
    }
    emit finished();
}

std::vector<std::vector<cv::Point> > cv_worker::findCircleContours(cv::Mat img)
{
    int minCricleW = 30;
    int minCricleH = 30;
    double minCricleArea = ((minCricleW+minCricleH)/4)*((minCricleW+minCricleH)/4)*3;

    std::vector<std::vector<cv::Point> > contours;
    std::vector<std::vector<cv::Point> >poly(contours.size());
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(img.clone(), contours, hierarchy, cv::RETR_CCOMP, cv::CHAIN_APPROX_NONE);

    std::vector<std::vector<cv::Point> > circleContours;
    unsigned int i;
    for (i=0;i<contours.size();i++)
    {
        std::vector<cv::Point> contour = contours[i];
        cv::Rect rect = cv::boundingRect(contour);
        float ar = float(rect.width) / float(rect.height);
        if (hierarchy[i][3] == -1 && rect.width >= minCricleW && rect.height >= minCricleH && 0.9f <= ar && ar <=1.1f)
        {
            circleContours.push_back(contour);
        }
    }
    qDebug()<<circleContours.size();
    return circleContours;
}
