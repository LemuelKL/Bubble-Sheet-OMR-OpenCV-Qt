#include "sheet.h"

using namespace std;
using namespace cv;

sheet::sheet()
{
}

sheet::sheet(QString absImgPath)
{
    _absImgPath = absImgPath;
    _isMarkedDone = false;
    _originalImage = QImage(absImgPath);
    _CV_originalImage = imread(absImgPath.toStdString());
}

QImage sheet::originalImage()
{
    return _originalImage;
}

QImage sheet::markedImage()
{
    // Take a copy of _CV_originalImage, and cv::drawContours() on it with _circleContours.
    // Convert the copy to QImage, return it.
    Mat blueprintMat = _CV_originalImage.clone();
    drawContours(blueprintMat, _circleContours, -1, Scalar(0, 255, 0), 2);
    return convertMat2QImage(blueprintMat);
}

QImage sheet::convertMat2QImage(Mat mat)    // Copy-pasted from the Internet
{
    // 8-bits unsigned, NO. OF CHANNELS=1
    if(mat.type() == CV_8UC1)
    {
        // Set the color table (used to translate colour indexes to qRgb values)
        QVector<QRgb> colorTable;
        for (int i = 0; i < 256; i++)
            colorTable.push_back(qRgb(i, i, i));
        // Copy input Mat
        //const uchar *qImageBuffer = (const uchar*)mat.data;   // Old style casting
        const uchar *qImageBuffer = const_cast<uchar*>(mat.data);
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, int(mat.step), QImage::Format_Indexed8);
        img.setColorTable(colorTable);
        return img;
    }
    // 8-bits unsigned, NO. OF CHANNELS=3
    if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        //const uchar *qImageBuffer = (const uchar*)mat.data;   // Old style casting
        const uchar *qImageBuffer = const_cast<uchar*>(mat.data);
        // Create QImage with same dimensions as input Mat
        QImage img(qImageBuffer, mat.cols, mat.rows, int(mat.step), QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}

Mat sheet::convert2WorkableMat(Mat rawMat)
{
    Mat grayMat;
    Mat blurryMat;
    Mat adaptThreshMat;
    cvtColor(rawMat, grayMat, COLOR_BGR2GRAY);
    GaussianBlur(grayMat, blurryMat, Size(3, 3), 1);
    adaptiveThreshold(blurryMat, adaptThreshMat, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 11, 2);
    return adaptThreshMat;
}

void sheet::mark_Generic(double relX1, double relY1, double relX2, double relY2, int ifUniformBubbles)
{
    // This function idealy should only alter the _circleContours (appending), not the images/mats themselves!
    Mat rawMat = _CV_originalImage.clone();
    Mat mat = convert2WorkableMat(rawMat);

    int x1 = int(relX1 * mat.cols);
    int y1 = int(relY1 * mat.rows);
    int x2 = int((relX2 - relX1) * mat.cols);
    int y2 = int((relY2 - relY1) * mat.rows);
    Rect ROI(x1, y1, x2, y2);
    Mat roiMat = mat(ROI);  // Note: this roiMat is not a copy, it's referencing.

    int minRadius = 35; int maxRadius = 100;
    double minCircleArea = minRadius * 3.00;

    vector<vector<Point> > ctns;
    vector<Vec4i> hierarchy;
    findContours(roiMat.clone(), ctns, hierarchy, RETR_CCOMP, CHAIN_APPROX_NONE, Point(x1, y1));

    vector<vector<Point> > circleCtns;
    vector<Rect> circleRects;
    unsigned long long i;
    for (i = 0; i < ctns.size(); i++)
    {
        Rect rect = boundingRect(ctns[i]);
        float ar = float(rect.width) / float(rect.height);
        if (hierarchy[i][3] == -1 && rect.width >= minRadius && rect.height >= minRadius && rect.width <= maxRadius && rect.height <= maxRadius && 0.9f <= ar && ar <= 1.1f)
        {
            double ctnArea = cv::contourArea(ctns[i], false);
            if (minCircleArea <= ctnArea)
            {
                double epsilon = 0.01*cv::arcLength(ctns[i], true);
                std::vector<cv::Point> approx;
                approxPolyDP(ctns[i], approx, epsilon, true);
                if (approx.size() > 5)
                {
                    if (!(isCtnDup(ctns[i])))
                    {
                        circleCtns.push_back(ctns[i]);
                        circleRects.push_back(rect);
                    }
                }
            }
        }
    }
    if (ifUniformBubbles == 2)
    {
        if (circleCtns.size() > 0)
        {
            vector<int> radii(unsigned(long(long(maxRadius))) + 1, 0);
            for (i = 0; i < circleRects.size(); i++)
            {
                if (circleRects.at(i).width <= maxRadius)
                {
                    radii.at(unsigned(long(long(circleRects.at(i).width)))) += 1;
                }
            }
            unsigned long long modeRadius = 0;
            for (i = 1; i < radii.size(); i++)
            {
                if (radii.at(i) > radii.at(modeRadius))
                {
                    modeRadius = i;
                }
            }
            vector<vector<Point> > finalCircleCtns;
            for (i = 0; i < circleRects.size(); i++)
            {
                if (abs(int(circleRects.at(i).width) - int(modeRadius)) < 2)
                {
                    finalCircleCtns.push_back(circleCtns.at(i));
                }
            }
            _circleContours.insert(_circleContours.end(), finalCircleCtns.begin(), finalCircleCtns.end());
        }
    }
    else
    {
        if (circleCtns.size() > 0)
        {
            _circleContours.insert(_circleContours.end(), circleCtns.begin(), circleCtns.end());
        }
    }

    emit mark_Generic_Done();
}

void sheet::unmarkInRoi(double relX1, double relY1, double relX2, double relY2)
{
    Mat rawMat = _CV_originalImage.clone();
    Mat mat = convert2WorkableMat(rawMat);

    int x1 = int(relX1 * mat.cols);
    int y1 = int(relY1 * mat.rows);
    int x2 = int((relX2 - relX1) * mat.cols);
    int y2 = int((relY2 - relY1) * mat.rows);
    Rect ROI(x1, y1, x2, y2);
    Mat roiMat = mat(ROI);

    vector<vector<Point> > ctns;
    vector<Vec4i> hierarchy;
    findContours(roiMat.clone(), ctns, hierarchy, RETR_CCOMP, CHAIN_APPROX_NONE, Point(x1, y1));

    unsigned long long i, j;
    for (i = 0; i < ctns.size(); i++)
    {
        for (j = 0; j < _circleContours.size(); j++)
        {
            if (_circleContours.at(j) == ctns.at(i))
            {
                _circleContours.erase(_circleContours.begin() + int(j));
            }
        }
    }
}

bool sheet::isCtnDup(vector<Point> ctns)
{
    unsigned long long i;
    for (i = 0; i < _circleContours.size(); i++)
    {
        if (_circleContours.at(i) == ctns)
            return true;
    }
    return false;
}

void sheet::mark_Generic_Done()
{

}

int sheet::nBubbles()
{
    return _nBubbles;
}

void sheet::loadCtnsToBubbles()
// (Initializes) nBubbles and _bubbleCoords (purge existing if found)
{
    _nBubbles = int(_circleContours.size());

    QVector<bubble> bs;

    for (unsigned long long i = 0; i < unsigned(long(long(_nBubbles))); i++)
    {
        bubble b(_circleContours[i]);
        bs.append(b);
    }
    _bubbleCoords = bs;

}
