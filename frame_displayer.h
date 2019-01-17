#ifndef FRAME_DISPLAYER_H
#define FRAME_DISPLAYER_H

#include <QLabel>
#include <QRubberBand>

class frame_displayer : public QLabel
{
    Q_OBJECT
public:
    frame_displayer(QWidget * parent = nullptr);
    //~frame_displayer();

    QWidget * _ui;
    QRubberBand* _rubberBand;
    QPoint _mouseClickPoint;
    Qt::MouseButton _lastClickedBtn;

signals:
    void mouseMoved(int, int);
    void mouseLeave();
    void mouseEnter();

    void roiSelectedToMark(QRect);
    void roiSelectedToRemoveMark(QRect);

protected slots:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void leaveEvent(QEvent * event) override;
    void enterEvent(QEvent * event) override;
};

#endif // FRAME_DISPLAYER_H
