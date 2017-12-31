#ifndef NCANVAS_H
#define NCANVAS_H

#include <QObject>
#include <QWidget>

class NStatusMessage;
class QLabel;

class NCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit NCanvas(QWidget *parent = nullptr);
    void setPos(QPointF _pos);
    void setMessage(NStatusMessage *_lab);

    protected:
//    bool event(QEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void tabletEvent(QTabletEvent *event) override;

signals:
//    void tabletStatusChanged(QPointF &pos, qreal &pressure);

private:
    QPointF nPos;
    qreal nPressure;
    NStatusMessage *nStatusMessage;

public slots:
};

#endif // NCANVAS_H
