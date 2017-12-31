#include "ntabwidget.h"
#include "ncanvasview.h"
#include <QLabel>
#include <QGraphicsProxyWidget>
#include "ncanvas.h"

NTabWidget::NTabWidget(QWidget *parent)
    : QTabWidget(parent)
{
    nView = new NCanvasView(this);
    nCanvas = new NCanvas;
    nCanvas->setGeometry(0, 0, 600, 400);
    nView->setReceiver(nCanvas);
    QGraphicsProxyWidget *ass = nScene.addWidget(nCanvas);
    nView->setMirror(ass);

    nView->setScene(&nScene);
    addTab(nView, tr("Untitled"));
}
