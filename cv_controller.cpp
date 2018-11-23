#include "cv_controller.h"

#include "cv_worker.h"

#include <QDebug>

cv_controller::cv_controller(QObject *parent) :
    QObject(parent),
    worker_(new cv_worker)
{
    worker_->moveToThread(&thread_);

    connect(&thread_, &QThread::finished, worker_, &QObject::deleteLater);
    connect(this, &cv_controller::start_working,
            worker_, &cv_worker::work);

    thread_.start();
}

cv_controller::~cv_controller()
{
    thread_.quit();
    thread_.wait();
}
