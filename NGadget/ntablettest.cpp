#include "ntablettest.h"
#include <QFormLayout>
#include <QTabletEvent>
#include <QLabel>
#include <QObject>

NTabletTest::NTabletTest(QWidget *parent)
    : QWidget(parent),
      nTabletTestLayout(new QFormLayout),
      xPos(new QLabel),
      yPos(new QLabel),
      nTabletPressure(new QLabel),
      nTabletRotation(new QLabel)
{
    nTabletTestLayout->addRow(tr("X: "), xPos);
    nTabletTestLayout->addRow(tr("Y: "), yPos);
    nTabletTestLayout->addRow(tr("Pressure: "), nTabletPressure);
    nTabletTestLayout->addRow(tr("Rotation: "), nTabletRotation);
    this->setLayout(nTabletTestLayout);
    this->setGeometry(QRect(600, 400, 360, 200));
}

void NTabletTest::tabletEvent(QTabletEvent *event)
{
    switch (event->type()) {
    case QEvent::TabletMove:
        xPos->setText(QString::number(event->x(), 10));
        yPos->setText(QString::number(event->y(), 10));
        nTabletPressure->setText(QString::number(event->pressure() * 2048));
        if (event->rotation() == 0)
            nTabletRotation->setText(tr("Could not be defined."));
        else
            nTabletRotation->setText(QString::number(event->rotation()));
        break;
    case QEvent::TabletRelease:
        nTabletPressure->setText(tr(""));
        break;
    default:
        break;
    }
}
