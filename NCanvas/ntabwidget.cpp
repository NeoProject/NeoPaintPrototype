#include "ntabwidget.h"
#include "ncanvasview.h"
#include <QLabel>
#include <QGraphicsProxyWidget>
#include "ncanvas.h"

NTabWidget::NTabWidget(QWidget *parent)
    : QTabWidget(parent)
{
//    nView = new NCanvasView(this);
//    nCanvas = new NCanvas;
//    nScene = new QGraphicsScene;
//    nCanvas->setGeometry(0, 0, 600, 400);
//    nView->setReceiver(nCanvas);
//    QGraphicsProxyWidget *ass = nScene->addWidget(nCanvas);
//    nView->setMirror(ass);


//    nView->setScene(nScene);
//    nView->setBackgroundRole(QPalette::Dark);
//    nView->setAlignment(Qt::AlignCenter);
//    addTab(nView, tr("Untitled"));

}

void NTabWidget::newCanvas()
{
    nView.append(new NCanvasView(this));
    nCanvas.append(new NCanvas);

    nScene.append(new QGraphicsScene);

    nCanvas.back()->setGeometry(0, 0, 600, 400);
    nView.back()->setReceiver(nCanvas.back());
    nView.back()->setMirror(nScene.back()->addWidget(nCanvas.back()));

    nView.back()->setScene(nScene.back());
    addTab(nView.back(), tr("Untitled"));

}
