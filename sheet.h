#ifndef SHEET_H
#define SHEET_H

#include <QVector>
#include <QVector2D>
#include <QImage>
#include <QFile>
#include <QFileInfo>
#include <QString>
#include <QtDebug>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <bubble.h>

class sheet
{
public:
    sheet();
    sheet(QString);
    bool isMarkedDone();

    void markDone();
    void markUndone();

    QImage originalImage();
    QImage markedImage();

    void mark_Generic(double, double, double, double, int);
    void unmarkInRoi(double, double, double, double);

    void loadCtnsToBubbles();
    int nBubbles();
    QVector<bubble> bubbles();

    void groupBubbles_generic();
    void groupBubbles_kMeanClustering(int k);

    void debugBubbles();

    int nQuestions();

signals:
    void mark_Generic_Done();

private:
    QString _absImgPath;

    QImage convertMat2QImage(cv::Mat);
    cv::Mat convert2WorkableMat(cv::Mat);
    bool isCtnDup(std::vector<cv::Point> ctns);

    QImage _originalImage;
    cv::Mat _CV_originalImage;

    std::vector<std::vector<cv::Point> > _circleContours;

    bool _isMarkedDone;
    int _nBubbles;
    int _nQuestions;
    bool _uniform_nB_inQ;
    bool _uniform_D_B2B;
    bool _uniform_D_Q2Q;
    QVector<bubble> _bubbles;

    QVector<QVector2D> _centroids;

    double distB2C(bubble b, QVector2D c);
    QVector2D newMeanCentroid(QVector<float> x, QVector<float> y);

};

#endif // SHEET_H
