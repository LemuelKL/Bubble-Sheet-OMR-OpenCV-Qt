#include "frame_displayer.h"

#include <QDebug>
#include <QMouseEvent>

frame_displayer::frame_displayer(QWidget * parent) : QLabel(parent)
{
    _ui = parent;
    _rubberBand = nullptr;
}

void frame_displayer::mousePressEvent(QMouseEvent *event)
// https://stackoverflow.com/questions/16527248/qrubberband-on-a-definite-label
{
    _lastClickedBtn = event->button();
    if (_lastClickedBtn == Qt::LeftButton)
    {
        _mouseClickPoint = event->pos();
        if(_rubberBand == nullptr)
            _rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
        _rubberBand->setGeometry(QRect(_mouseClickPoint, _mouseClickPoint));
        _rubberBand->show();
    }
}

void frame_displayer::mouseMoveEvent(QMouseEvent *event)
{
    if(_rubberBand != nullptr)
    {
        if (_lastClickedBtn == Qt::LeftButton)
        {
            QPoint mouseCurrentPoint = event->pos();
            _rubberBand->setGeometry(QRect(_mouseClickPoint, mouseCurrentPoint).normalized());
            qDebug() << _rubberBand->size();
        }
    }
}

void frame_displayer::mouseReleaseEvent(QMouseEvent *event)
{
    if(_rubberBand != nullptr)
    {
        _rubberBand->hide();
        _rubberBand->clearMask();
    }
}
