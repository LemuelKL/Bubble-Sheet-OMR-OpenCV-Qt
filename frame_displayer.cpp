#include "frame_displayer.h"

#include <QDebug>
#include <QMouseEvent>
#include <QCursor>

frame_displayer::frame_displayer(QWidget * parent) : QLabel(parent)
{
    _ui = parent;
    _rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
    this->setMouseTracking(false);
}

void frame_displayer::mousePressEvent(QMouseEvent *event)
// https://stackoverflow.com/questions/16527248/qrubberband-on-a-definite-label
{
    _lastClickedBtn = event->button();
    if (_lastClickedBtn == Qt::LeftButton)
    {
        _mouseClickPoint = event->pos();
        _rubberBand->setGeometry(QRect(_mouseClickPoint, _mouseClickPoint));
        _rubberBand->show();
    }
}

void frame_displayer::mouseMoveEvent(QMouseEvent *event)
{
    if(_rubberBand != nullptr)
    {
        if (this->underMouse())
        {
            if (_lastClickedBtn == Qt::LeftButton)
            {
                QPoint mouseCurrentPoint = event->pos();
                auto clamp_rect = rect();
                mouseCurrentPoint.rx() = std::min(clamp_rect.right(), std::max(clamp_rect.left(), mouseCurrentPoint.x()));
                mouseCurrentPoint.ry() = std::min(clamp_rect.bottom(), std::max(clamp_rect.top(), mouseCurrentPoint.y()));
                _rubberBand->setGeometry(QRect(_mouseClickPoint, mouseCurrentPoint).normalized());
            }
        }
    }
}

void frame_displayer::mouseReleaseEvent(QMouseEvent *event)
{
    _mouseClickPoint = QPoint();
    _lastClickedBtn = Qt::MidButton;
    if(_rubberBand != nullptr)
    {
        _rubberBand->hide();
        _rubberBand->clearMask();
    }
}
