#ifndef NABOUT_H
#define NABOUT_H

#include <QObject>
#include <QDialog>
#include <QWidget>

class QHBoxLayout;
class QLabel;

class NAbout : public QDialog
{
    Q_OBJECT
public:
    NAbout(QString info, QWidget *parent = 0);

private:
    QLabel *nAboutLabel;
    QHBoxLayout *nAboutLayout;
};

#endif // NABOUT_H
