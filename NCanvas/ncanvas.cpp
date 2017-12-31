#include "ncanvas.h"
#include <QTabletEvent>
#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include <QLabel>
#include "../NGadget/nstatusmessage.h"

NCanvas::NCanvas(QWidget *  parent) : QWidget(parent)
{
    setFocus();
}

void NCanvas::setPos(QPointF _pos)
{
    nPos = _pos;
    return;
}

void NCanvas::setMessage(NStatusMessage *_lab)
{
    nStatusMessage = _lab;
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
    nPressure = event->pressure();
    qDebug()<< nPressure * 2048<< endl;
    nStatusMessage->setText("X: " + QString::number(nPos.x()) + " Y: " + QString::number(nPos.y()) + " Pressure: " + QString::number(nPressure * 2048));
//    emit tabletStatusChanged(nPos, nPressure);
    update();
}

