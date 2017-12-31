#ifndef NMAINWINDOW_H
#define NMAINWINDOW_H

#include <QMainWindow>

class NStatusBar;
class NToolBar;
class NMenuBar;
class NTabWidget;
class QMenu;
class NDockWidget;
class NAbout;
class NTabletTest;

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

    NDockWidget *neoPrototype;
    NTabWidget *neoTabWidget;

    NAbout *neoAbout;
    NTabletTest *neoTabletTest;


    void initWidget();
    void initConnection();
};

#endif // NMAINWINDOW_H
