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

    void setMode(int);
    int mode();
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

private:
    int _mode;  // 0-, 1-Marking, 2-Grouping
};

#endif // FRAME_DISPLAYER_H
