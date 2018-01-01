#include "ncanvas.h"
#include <QTabletEvent>
#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include <QLabel>
#include "../NGadget/nstatusmessage.h"
#include <QImage>

NCanvas::NCanvas(QWidget *  parent)
    : QWidget(parent)
{
    setFocus();
    nImage = QImage(600, 400, QImage::Format_ARGB32_Premultiplied);
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
    QPainter painter;
    painter.begin(&nImage);
    painter.drawPoint(nPos);
    painter.end();
    painter.begin(this);
    painter.drawImage(QRect(0, 0, 600, 400), nImage);
    painter.end();
}

void NCanvas::tabletEvent(QTabletEvent *event)
{
    nPressure = event->pressure();
//    nStatusMessage->setText("X: " + QString::number(nPos.x()) + " Y: " + QString::number(nPos.y()) + " Pressure: " + QString::number(nPressure * 2048));
//    emit tabletStatusChanged(nPos, nPressure);
//    qDebug()<< "here"<< endl;
    update();

}

