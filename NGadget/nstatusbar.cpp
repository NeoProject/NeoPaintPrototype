#include "nstatusbar.h"
#include "nstatusmessage.h"

NStatusBar::NStatusBar(QWidget *parent)
    : QStatusBar(parent),
      nStatusMessage(new NStatusMessage)
{

}

NStatusBar::~NStatusBar()
{

}

void NStatusBar::changeStatus(QPointF pos, qreal pressure)
{
    QString info;
    info = "X: " + QString::number(pos.x()) + " Y: " + QString::number(pos.y()) + " Pressure: " + QString::number(pressure * 2048);
//    info.arg(tr("X: ")).arg(pos.x()).arg(tr(" Y: ")).arg(pos.y()).arg(tr(" Pressure: ")).arg(pressure * 2048);
    nStatusMessage->setText(info);
    addPermanentWidget(nStatusMessage);
}
