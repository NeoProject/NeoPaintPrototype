#ifndef NTABLETTEST_H
#define NTABLETTEST_H

#include <QObject>
#include <QWidget>

class QFormLayout;
class QLabel;

class NTabletTest : public QWidget
{
    Q_OBJECT
public:
    explicit NTabletTest(QWidget *parent = nullptr);

protected:
    void tabletEvent(QTabletEvent *event) override;

private:
    QFormLayout *nTabletTestLayout;
    QLabel *xPos, *yPos;
    QLabel *nTabletPressure, *nTabletRotation;

signals:

public slots:
};

#endif // NTABLETTEST_H
