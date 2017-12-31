#include "ncolorcontainer.h"
#include <QColorDialog>
#include <QHBoxLayout>

NColorContainer::NColorContainer(QWidget *parent)
    : NDockWidget(parent),
      nLayout(new QHBoxLayout)
{
}
