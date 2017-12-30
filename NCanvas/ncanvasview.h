#ifndef NCANVASVIEW_H
#define NCANVASVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>

class NCanvasView : public QObject, public QGraphicsView
{
public:
    NCanvasView();
};

#endif // NCANVASVIEW_H
