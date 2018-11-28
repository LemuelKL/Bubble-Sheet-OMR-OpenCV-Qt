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
    void process();

signals:
    void finished();
    void error(QString errStr);

    void sendImg(QImage img);

private:
    QStringList mImgPaths;
    int mNPages;
    std::vector<cv::Mat> mDoc;

    QImage MatToQImage(const cv::Mat& mat);
    std::vector<std::vector<cv::Point> > findCircleContours(cv::Mat img);

};

#endif // CV_WORKER_H
