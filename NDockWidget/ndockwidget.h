#ifndef NDOCKWIDGET_H
#define NDOCKWIDGET_H

#include <QObject>
#include <QWidget>
#include <QDockWidget>

class NDockWidget : public QDockWidget
{
public:
    explicit NDockWidget(QWidget *parent = nullptr);
};

#endif // NDOCKWIDGET_H
