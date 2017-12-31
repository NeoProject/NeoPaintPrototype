#include "nmainwindow.h"
#include "NGadget/nstatusbar.h"
#include "NGadget/nmenubar.h"
#include "NGadget/ntoolbar.h"
#include <QLabel>
#include "NGadget/nabout.h"
#include "NCanvas/ntabwidget.h"
#include <QMenu>
#include <QAction>
#include "NGadget/ntablettest.h"
#include "NDockWidget/ndockwidget.h"

NMainWindow::NMainWindow(QWidget *parent)
    : QMainWindow(parent),
      neoStatusBar(new NStatusBar(this)),
      neoMenuBar(new NMenuBar(this)),
      neoToolBar(new NToolBar(this)),
      neoTabWidget(new NTabWidget(this)),
      neoPrototype(new NDockWidget(this))
{
    initWidget();
}

NMainWindow::~NMainWindow()
{

}

void NMainWindow::initWidget()
{
    setStatusBar(neoStatusBar);
    setMenuBar(neoMenuBar);
    addToolBar(neoToolBar);
    setCentralWidget(neoTabWidget);
    addDockWidget(Qt::LeftDockWidgetArea, neoPrototype);
}
