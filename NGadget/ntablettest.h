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
    void paintEvent(QPaintEvent *event) override;

private:
    QFormLayout *nTabletTestLayout;
    QLabel *xPos, *yPos;
    QLabel *nTabletPressure, *nTabletRotation;

    int x, y;
    qreal pressure;

signals:

public slots:
};

#endif // NTABLETTEST_H
