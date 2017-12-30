#ifndef NTOOLBAR_H
#define NTOOLBAR_H

#include <QObject>
#include <QToolBar>
#include <QWidget>

class NToolBar : public QToolBar
{
    Q_OBJECT

public:
    NToolBar(QWidget *parent = 0);
};

#endif // NTOOLBAR_H
