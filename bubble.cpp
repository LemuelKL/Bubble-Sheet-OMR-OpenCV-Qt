#include "bubble.h"

using namespace std;
using namespace cv;

bubble::bubble()
{

}

bubble::bubble(vector<Point> ctn)
{
    Rect rect = boundingRect(ctn);
    _cx = rect.x + rect.width / 2;
    _cy = rect.y + rect.height / 2;
    _r = rect.width + rect.height / 4;

    _centroidID = -1;
    _optionNum = -1;
    _questionNum = -1;
}

int bubble::optionNum()
{
    return _optionNum;
}

void bubble::setOptionNum(int num)
{
    _optionNum = num;
}

int bubble::questionNum()
{
    return _questionNum;
}

void bubble::setQuestionNum(int n)
{
    _questionNum = n;
}

bool bubble::isBlackened()
{
    return _isBlackened;
}

void bubble::setBlackened(bool state)
{
    _isBlackened = state;
}

int bubble::cx()
{
    return _cx;
}

int bubble::cy()
{
    return _cy;
}

int bubble::r()
{
    return _r;
}

int bubble::centroidID()
{
    return _centroidID;
}

void bubble::setCentroidID(int id)
{
    _centroidID = id;
}
