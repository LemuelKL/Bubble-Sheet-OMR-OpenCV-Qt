#ifndef BUBBLE_H
#define BUBBLE_H

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>

class bubble
{
public:
    bubble();
    bubble(std::vector<cv::Point>);

    int optionNum();
    void setOptionNum(int);
    int questionNum();
    void setQuestionNum(int);
    bool isBlackened();
    void setBlackened(bool);

    int cx();
    int cy();
    int r();

    void setCentroidID(int id);
    int centroidID();

private:
    int _optionNum;
    int _questionNum;
    bool _isBlackened;

    int _cx;
    int _cy;
    int _r;

    int _centroidID;

};

#endif // BUBBLE_H
