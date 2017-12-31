#ifndef NCANVASVIEW_H
#define NCANVASVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>

class NCanvasScene;

class NCanvasView : public QObject, public QGraphicsView
{
public:
    NCanvasView(QWidget *parent = nullptr);
    void setReceiver(QWidget *_receiver);
    void setMirror(QGraphicsProxyWidget *_mirror);
    void setNeoScene(QGraphicsScene *scene);
protected:
    void tabletEvent(QTabletEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

public:

private:
    qreal nScale;
    QWidget *receiver;
    QGraphicsScene *nScene;
    QGraphicsProxyWidget *nMirror;
};

#endif // NCANVASVIEW_H
