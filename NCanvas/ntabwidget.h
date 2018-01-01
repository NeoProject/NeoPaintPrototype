#ifndef NTABWIDGET_H
#define NTABWIDGET_H

#include <QObject>
#include <QWidget>
#include <QTabWidget>
#include <QGraphicsScene>
#include <QList>

class NCanvasView;
class NCanvas;
class QGraphicsProxyWidget;

class NTabWidget : public QTabWidget
{
public:
    explicit NTabWidget(QWidget *parent = nullptr);

public slots:
    void newCanvas();

public:
    QList<NCanvas *> nCanvas;
    QList<NCanvasView *> nView;
    QList<QGraphicsScene *> nScene;
//    QList<QGraphicsProxyWidget *> nMirror;
//    NCanvas *nCanvas;
//    NCanvasView *nView;
//    QGraphicsScene *nScene;
};

#endif // NTABWIDGET_H
