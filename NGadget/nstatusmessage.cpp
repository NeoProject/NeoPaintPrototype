#include "nstatusmessage.h"

NStatusMessage::NStatusMessage(QString info, QWidget *parent)
    : QLabel(parent)
{
    setText(info);
}
