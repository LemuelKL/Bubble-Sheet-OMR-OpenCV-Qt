#ifndef CV_WORKER_H
#define CV_WORKER_H

#include <QObject>
#include <QImage>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

class cv_worker : public QObject {
    Q_OBJECT

public:
    cv_worker(QStringList paths);
    ~cv_worker();

public slots:
    void identify(int startP, int endP, int METHOD);

signals:
    void sendImgs(std::vector<QImage> imgs, int startP, int endP);

private:
    QStringList mImgPaths;
    int mNPages;

    QImage MatToQImage(const cv::Mat& mat);
    std::vector<std::vector<cv::Point> > generic(cv::Mat img);

};

#endif // CV_WORKER_H
