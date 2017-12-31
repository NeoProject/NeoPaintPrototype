#include "ncanvas.h"
#include <QTabletEvent>
#include <QDebug>
#include <QPainter>

NCanvas::NCanvas(QWidget *parent) : QWidget(parent)
{

}

void NCanvas::setPos(QPointF _pos)
{
    nPos = _pos;
    return;
}

bool NCanvas::event(QEvent *event)
{
    QTabletEvent *nTabletEvent = static_cast<QTabletEvent *>(event);
    switch (event->type()) {
    case QEvent::TabletMove:
        qDebug()<< nPos<< endl;
        qDebug()<< nTabletEvent->pressure()<< endl;
        break;
    default:
        break;
    }
}
