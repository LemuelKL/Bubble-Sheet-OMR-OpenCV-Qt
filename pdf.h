#ifndef PDF_H
#define PDF_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QImage>
#include <QDebug>

#include <Magick++.h>
#include <wand/magick_wand.h>

class pdf : public QObject
{
    Q_OBJECT
public:
    pdf();
    pdf(QString absPath2PDF);
    QString fileName();
    QString fileDirectory();
    QVector<QString> convertPDF2Img(QString destPath, QString fNamePrefix, QString imgFormat);

signals:
    void progressUpdated(double);
    void finishedConversion();

private:
    QString _absPathToPDF;
    Magick::Image _ImageMagickImg;
    int nPages();
};

#endif // PDF_H
