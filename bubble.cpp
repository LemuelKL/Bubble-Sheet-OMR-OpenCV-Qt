#include "bubble.h"

using namespace std;
using namespace cv;

bubble::bubble(vector<Point> ctn)
{
    bubble
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

int bubble::optionNum()
{
    return _optionNum;
}

void bubble::setOptionNum(int num)
{
    _optionNum = num;
}
