#include "cv_controller.h"

cv_controller::cv_controller(QStringList imgPaths)
{
    workerThread = new QThread;
    worker = new cv_worker(imgPaths);
    worker->moveToThread(workerThread);

    connect(worker, SIGNAL(sendImgs(std::vector<QImage>, int, int)), this, SLOT(handleImgs(std::vector<QImage>, int, int)));
    connect(this, SIGNAL(identify_generic(int, int, int)), worker, SLOT(identify(int, int, int)));
    workerThread->start();
}

cv_controller::~cv_controller()
{
    workerThread->quit();
}

void cv_controller::handleImgs(std::vector<QImage> imgs, int startP, int endP)
{
    emit sendImgsToUI(imgs, startP, endP);
}

void cv_controller::invoke_identify_generic(int startP, int endP)
{
    emit identify_generic(startP, endP, 0);
}
