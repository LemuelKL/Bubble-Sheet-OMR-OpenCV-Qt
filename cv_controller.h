#ifndef CV_CONTROLLER_H
#define CV_CONTROLLER_H

#include <QObject>
#include <QThread>

#include <cv_worker.h>

class cv_controller : public QObject
{
    Q_OBJECT
    QThread* workerThread;
    cv_worker* worker;
public:
    cv_controller(QStringList imgPaths);
    ~cv_controller();

    void invoke_identify_generic(int startP, int endP);

public slots:
    void handleImgs(std::vector<QImage> imgs, int startP, int endP);
signals:
    void sendImgsToUI(std::vector<QImage> imgs, int startP, int endP);

    void identify_generic(int startP, int endP, int METHOD);
};

#endif // CV_CONTROLLER_H
