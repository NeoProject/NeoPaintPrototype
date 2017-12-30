#include "ntabwidget.h"
#include "ncanvasview.h"
#include <QLabel>
#include <QGraphicsProxyWidget>

NTabWidget::NTabWidget(QWidget *parent)
    : QTabWidget(parent)
{
    nView = new NCanvasView(this);
    QLabel *lab = new QLabel(tr("ass we can"));
    QGraphicsProxyWidget *ass = nScene.addWidget(lab);
    ass->setRotation(180);
    nView->setScene(&nScene);
    addTab(nView, tr("ass"));
}
