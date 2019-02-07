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

    int optionNum();
    void setOptionNum(int);
    bool isBlackened();
    void setBlackened(bool);

    int cx();
    int cy();
    int r();

private:
    int _optionNum;
    bool _isBlackened;

    int _cx;
    int _cy;
    int _r;

};

#endif // BUBBLE_H