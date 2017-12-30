#ifndef NSTATUSBAR_H
#define NSTATUSBAR_H

#include <QObject>
#include <QStatusBar>
#include <QWidget>

class NStatusBar : public QStatusBar
{
    Q_OBJECT

public:
    NStatusBar(QWidget *parent = 0);
    ~NStatusBar();
};

#endif // NSTATUSBAR_H
