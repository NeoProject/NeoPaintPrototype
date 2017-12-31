#include "ncanvasview.h"
#include <QTabletEvent>
#include <QDebug>
#include <QApplication>
#include <QGraphicsProxyWidget>
#include "ncanvas.h"
#include <QWheelEvent>

NCanvasView::NCanvasView(QWidget *parent)
    : QObject(parent),
      QGraphicsView(parent),
      nScale(1.0)
{

}

void NCanvasView::setReceiver(QWidget *_receiver)
{
    receiver = _receiver;
    return;
}

void NCanvasView::setMirror(QGraphicsProxyWidget *_mirror)
{
    nMirror = _mirror;
    return;
}

void NCanvasView::setNeoScene(QGraphicsScene *scene)
{
    nScene = scene;
    return;
}

void NCanvasView::tabletEvent(QTabletEvent *event)
{
    QPointF scenePos = mapToScene(event->pos());
    QPointF widgetPos = nMirror->mapFromScene(scenePos);
    static_cast<NCanvas *>(receiver)->setPos(widgetPos);
    QApplication::sendEvent(receiver, event);
}

void NCanvasView::wheelEvent(QWheelEvent *event)
{
    if (event->delta() > 0) {
        nScale *= 1.25;
        nMirror->setScale(nScale);
    } else {
        nScale *= 0.8;
        nMirror->setScale(nScale);
    }
}
