#ifndef NMENUBAR_H
#define NMENUBAR_H

#include <QObject>
#include <QMenuBar>
#include <QWidget>

class NMenuBar : public QMenuBar
{
    Q_OBJECT

public:
    NMenuBar(QWidget *parent = 0);
};

#endif // NMENUBAR_H
