#include "nabout.h"
#include <QLabel>
#include <QHBoxLayout>

NAbout::NAbout(QString info, QWidget *parent)
    : QDialog(parent),
      nAboutLabel(new QLabel),
      nAboutLayout(new QHBoxLayout)
{
    nAboutLabel->setText(info);
    nAboutLayout->addWidget(nAboutLabel);
    this->setLayout(nAboutLayout);
}
