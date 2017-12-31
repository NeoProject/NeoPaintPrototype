#include "nmainwindow.h"
#include "NGadget/nstatusbar.h"
#include "NGadget/nmenubar.h"
#include "NGadget/ntoolbar.h"
#include <QLabel>
#include <NCanvas/ncanvas.h>
#include "NGadget/nabout.h"
#include "NCanvas/ntabwidget.h"
#include <QMenu>
#include <QAction>
#include "NGadget/ntablettest.h"
#include "NDockWidget/ndockwidget.h"
#include "NGadget/nabout.h"
#include "NGadget/ntablettest.h"

NMainWindow::NMainWindow(QWidget *parent)
    : QMainWindow(parent),
      neoStatusBar(new NStatusBar(this)),
      neoMenuBar(new NMenuBar(this)),
      neoToolBar(new NToolBar(this)),
      neoTabWidget(new NTabWidget(this)),
      neoPrototype(new NDockWidget(this)),
      neoAbout(new NAbout(tr("NeoPaintPrototype"))),
      neoTabletTest(new NTabletTest)
{
    initWidget();
    initConnection();
    setDockNestingEnabled(true);
    neoPrototype->setAllowedAreas(Qt::LeftDockWidgetArea);
    neoPrototype->setMinimumWidth(300);
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

void NMainWindow::initConnection()
{
    connect(neoMenuBar->NFile.Close, &QAction::triggered, this, &NMainWindow::close);

    connect(neoMenuBar->NHelp.About, &QAction::triggered, neoAbout, &NAbout::show);
    connect(neoMenuBar->NHelp.TabletTest, &QAction::triggered, neoTabletTest, &NTabletTest::show);

//    connect(neoTabWidget->nCanvas, &NCanvas::tabletStatusChanged, neoStatusBar, &NStatusBar::changeStatus);
}
