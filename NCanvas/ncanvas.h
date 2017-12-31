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
    bool event(QEvent *event) override;

signals:

private:
    QPointF nPos;

public slots:
};

#endif // NCANVAS_H