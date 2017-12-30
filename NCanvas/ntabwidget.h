#ifndef NTABWIDGET_H
#define NTABWIDGET_H

#include <QObject>
#include <QWidget>
#include <QTabWidget>

class NTabWidget : public QTabWidget
{
public:
    explicit NTabWidget(QWidget *parent = nullptr);
};

#endif // NTABWIDGET_H
