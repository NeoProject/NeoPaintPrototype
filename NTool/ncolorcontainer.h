#ifndef NCOLORCONTAINER_H
#define NCOLORCONTAINER_H

#include <QObject>
#include <QWidget>
#include "../NDockWidget/ndockwidget.h"


class QColorDialog;
class QHBoxLayout;

class NColorContainer : public NDockWidget
{
public:
    explicit NColorContainer(QWidget *parent = nullptr);

public:
    QHBoxLayout *nLayout;
};

#endif // NCOLORCONTAINER_H
