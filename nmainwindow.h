#ifndef NMAINWINDOW_H
#define NMAINWINDOW_H

#include <QMainWindow>

class NStatusBar;
class NToolBar;
class NMenuBar;
class NTabWidget;
class QMenu;

class NMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    NMainWindow(QWidget *parent = 0);
    ~NMainWindow();

private:
    NStatusBar *neoStatusBar;
    NMenuBar *neoMenuBar;
    NToolBar *neoToolBar;

    NTabWidget *neoTabWidget;

    void initWidget();

};

#endif // NMAINWINDOW_H
