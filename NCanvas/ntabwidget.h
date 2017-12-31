#ifndef NTABWIDGET_H
#define NTABWIDGET_H

#include <QObject>
#include <QWidget>
#include <QTabWidget>
#include <QGraphicsScene>

class NCanvasView;
class NCanvas;

class NTabWidget : public QTabWidget
{
public:
    explicit NTabWidget(QWidget *parent = nullptr);

public:
    NCanvas *nCanvas;
    NCanvasView *nView;
    QGraphicsScene nScene;
};

#endif // NTABWIDGET_H
