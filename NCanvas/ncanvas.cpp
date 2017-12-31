#include "ncanvas.h"
#include <QTabletEvent>
#include <QDebug>
#include <QPainter>
#include <QPaintEvent>

NCanvas::NCanvas(QWidget *  parent) : QWidget(parent)
{

}

void NCanvas::setPos(QPointF _pos)
{
    nPos = _pos;
    return;
}

//bool NCanvas::event(QEvent *event)
//{
//    if (event->type() != QEvent::TabletPress && event->type() != QEvent::TabletMove && event->type() != QEvent::TabletRelease)
//        return false;

//    QTabletEvent *nTabletEvent = static_cast<QTabletEvent *>(event);

//    switch (event->type()) {
//    case QEvent::TabletMove:
//        nPressure = nTabletEvent->pressure();
//        qDebug()<< "paint?"<< endl;
//        break;

//    default:
//        break;
//    }
//    event->accept();
//    repaint();
//    qDebug()<< "update?"<< endl;
//    QWidget::event(event);
//}

void NCanvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawLine(QPoint(300, 200), nPos);
    painter.end();
}

void NCanvas::tabletEvent(QTabletEvent *event)
{
    qDebug()<< "received."<< endl;
    emit tabletStatusChanged(nPos, nPressure);
    update();
}
