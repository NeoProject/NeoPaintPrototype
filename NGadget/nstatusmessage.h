#ifndef NSTATUSMESSAGE_H
#define NSTATUSMESSAGE_H

#include <QObject>
#include <QWidget>
#include <QLabel>

class NStatusMessage : public QLabel
{
public:
    explicit NStatusMessage(QString info = nullptr, QWidget *parent = nullptr);
};

#endif // NSTATUSMESSAGE_H
