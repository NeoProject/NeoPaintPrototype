#ifndef NTABWIDGET_H
#define NTABWIDGET_H

#include <QObject>
#include <QWidget>
#include <QTabWidget>
#include <QGraphicsScene>

class NCanvasView;

class NTabWidget : public QTabWidget
{
public:
    explicit NTabWidget(QWidget *parent = nullptr);

public:
    NCanvasView *nView;
    QGraphicsScene nScene;
};

#endif // NTABWIDGET_H
