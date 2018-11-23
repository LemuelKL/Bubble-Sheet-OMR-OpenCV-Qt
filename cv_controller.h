#ifndef CV_CONTROLLER_H
#define CV_CONTROLLER_H

#include <QObject>
#include <QThread>

class cv_worker;

class cv_controller : public QObject
{
    Q_OBJECT
public:
    explicit cv_controller(QObject *parent = nullptr);
    ~cv_controller();

signals:
    void start_working(QStringList);

private:
    QThread thread_;
    cv_worker *worker_;
};

#endif // CV_CONTROLLER_H
