#ifndef CV_WORKER_H
#define CV_WORKER_H

#include <QObject>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

class cv_worker : public QObject
{
    Q_OBJECT
public:
    explicit cv_worker(QObject *obj = nullptr);

    void print_working_thread();

    void work(QStringList);
};

#endif // CV_WORKER_H
