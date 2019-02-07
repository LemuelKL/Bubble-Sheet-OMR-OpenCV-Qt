#ifndef QUESTION_H
#define QUESTION_H

#include <QVector>
#include <bubble.h>

class question
{
public:
    question();

    void setQNum(int);

private:
    QVector<bubble> _bubbles;
    int _qNum;

};

#endif // QUESTION_H
