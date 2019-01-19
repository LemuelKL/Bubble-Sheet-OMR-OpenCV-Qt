#ifndef BUBBLE_H
#define BUBBLE_H

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>

class bubble
{
public:
    bubble(std::vector<cv::Point>);

    bool isBlackened();
    void setBlackened(bool);

    int cx();
    int cy();
    int r();
    int optionNum();
    void setOptionNum(int);

private:
    int _cx;
    int _cy;
    int _r;
    int _optionNum;
    bool _isBlackened;

};

#endif // BUBBLE_H
