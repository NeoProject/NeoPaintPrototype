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

public:

};

#endif // NCANVASVIEW_H
