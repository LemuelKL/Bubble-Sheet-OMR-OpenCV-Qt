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

class sheet
{
public:
    sheet();
    sheet(QString);
    bool isMarkedDone();

    void markDone();
    void markUndone();

    QVector<QVector2D> bubbleCoords();
    QImage originalImage();
    QImage markedImage();

    void mark_Generic(double, double, double, double, int);
    void unmarkInRoi(double, double, double, double);



signals:
    void mark_Generic_Done();
private:
    QImage convertMat2QImage(cv::Mat);
    cv::Mat convert2WorkableMat(cv::Mat);
    bool isCtnDup(std::vector<cv::Point> ctns);

    QString _absImgPath;
    bool _isMarkedDone;
    QVector<QVector2D> _bubbleCoords;
    QImage _originalImage;
    cv::Mat _CV_originalImage;

    std::vector<std::vector<cv::Point> > _circleContours;

    int _nBubbles;
    int _nQuestions;
    bool _uniform_nB_inQ;
    bool _uniform_D_B2B;
    bool _uniform_D_Q2Q;
};

#endif // SHEET_H
