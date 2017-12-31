#ifndef NSTATUSBAR_H
#define NSTATUSBAR_H

#include <QObject>
#include <QStatusBar>
#include <QWidget>

class NStatusMessage;

class NStatusBar : public QStatusBar
{
    Q_OBJECT

public:
    NStatusBar(QWidget *parent = 0);
    ~NStatusBar();

private:
    NStatusMessage *nStatusMessage;

public slots:
    void changeStatus(QPointF pos, qreal pressure);
};

#endif // NSTATUSBAR_H
