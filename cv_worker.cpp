#include "cv_worker.h"

#include <QDebug>
#include <QThread>

cv_worker::cv_worker(QObject *obj) : QObject(obj)
{
}

void cv_worker::print_working_thread()
{
    qDebug()<<QThread::currentThread();
}

void cv_worker::work(QStringList ImgPaths)
{
    int i;
    for ( i=0 ; i<ImgPaths.length() ; i++ )
    {
        qDebug()<<QThread::currentThread();
    }
}
