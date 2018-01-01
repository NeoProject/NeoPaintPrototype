#include "ncanvasview.h"
#include <QTabletEvent>
#include <QDebug>
#include <QApplication>
#include <QGraphicsProxyWidget>
#include "ncanvas.h"
#include <QWheelEvent>
#include <QScrollBar>
#include <QScrollArea>
#include <QTransform>

NCanvasView::NCanvasView(QWidget *parent)
    : QGraphicsView(parent),
      nScale(1),
      nRotation(0)

{
//    verticalScroll->setMaximum(100);
//    setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
//    setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
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

void NCanvasView::openFile(const QString &FileName)
{
    static_cast<NCanvas *>(receiver)->nImage.load(FileName);
    static_cast<NCanvas *>(receiver)->update();
}

void NCanvasView::saveFile(const QString &FileName)
{
    qDebug()<< FileName<< endl;
    static_cast<NCanvas *>(receiver)->nImage.save(FileName);
}

void NCanvasView::tabletEvent(QTabletEvent *event)
{

    QPointF scenePos = mapToScene(event->pos());
    QPointF widgetPos = nMirror->mapFromScene(scenePos);
    static_cast<NCanvas *>(receiver)->setPos(widgetPos);
    qDebug()<< "ass"<< endl;
    QApplication::sendEvent(receiver, event);
}

void NCanvasView::wheelEvent(QWheelEvent *event)
{
    qDebug()<< "as"<< endl;
//    qDebug()<< verticalScroll->value();
    if (event->delta() > 0) {
        transform.scale(1.25, 1.25);
    } else {
        transform.scale(0.8, 0.8);
    }
    setTransform(transform);
}

void NCanvasView::keyPressEvent(QKeyEvent *event)
{

    if (event->modifiers() == Qt::ControlModifier) {
        switch (event->key()) {
        case Qt::Key_Equal:
            transform.rotate(15);
            setTransform(transform);
            break;
        case Qt::Key_Minus:
            transform.rotate(-15);
            setTransform(transform);
            break;
        default:
            break;
        }
    }
}
