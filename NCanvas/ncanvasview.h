#ifndef NCANVASVIEW_H
#define NCANVASVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>


class NCanvasScene;
class QScrollBar;
class QScrollArea;

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
    void keyPressEvent(QKeyEvent *event) override;

public:
    QScrollBar *verticalScroll;
    QScrollBar *horizontalScroll;
    QScrollArea *nArea;

private:
    QTransform transform;
    qreal nScale;
    qreal nRotation;
    QWidget *receiver;
    QGraphicsScene *nScene;
    QGraphicsProxyWidget *nMirror;
};

#endif // NCANVASVIEW_H
