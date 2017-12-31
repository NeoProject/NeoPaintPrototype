#ifndef NCANVAS_H
#define NCANVAS_H

#include <QObject>
#include <QWidget>

class NCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit NCanvas(QWidget *parent = nullptr);
    void setPos(QPointF _pos);

    protected:
//    bool event(QEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void tabletEvent(QTabletEvent *event) override;

//signals:
//    void tabletStatusChanged(int x, int y, qreal pressure);

private:
    QPointF nPos;
    qreal nPressure;

public slots:
};

#endif // NCANVAS_H
