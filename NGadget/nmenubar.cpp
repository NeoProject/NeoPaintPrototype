#include "nmenubar.h"
#include <QMenu>
#include <QAction>
#include <QFileDialog>

NMenuBar::NMenuBar(QWidget *parent)
    : QMenuBar(parent),
      nFile(new QMenu(tr("&File"), this)),
      nEdit(new QMenu(tr("&Edit"), this)),
      nHelp(new QMenu(tr("&Help"), this))
{
    setupSelf();
}

void NMenuBar::setupSelf()
{
    addMenu(nFile);
    addMenu(nEdit);
    addMenu(nHelp);

    setupFile();
    setupEdit();
    setupHelp();
    setupConnection();
}

void NMenuBar::setupFile()
{
    NFile.Open = new QAction(tr("&Open"));
    NFile.Save = new QAction(tr("&Save"));
    NFile.SaveAs = new QMenu(tr("Save As"));
    NFile.Close = new QAction(tr("&Exit"));

    nFile->addAction(NFile.Open);
    nFile->addAction(NFile.Save);
    nFile->addSeparator();
    nFile->addMenu(NFile.SaveAs);
    nFile->addAction(NFile.Close);

    NFile.SaveAsMenu.SaveAsPng = new QAction(tr("Save as png"));
    NFile.SaveAsMenu.SaveAsJpg = new QAction(tr("Save as jpg"));
    NFile.SaveAsMenu.SaveAsJpeg = new QAction(tr("Save as jpeg"));

    NFile.SaveAs->addAction(NFile.SaveAsMenu.SaveAsPng);
    NFile.SaveAs->addAction(NFile.SaveAsMenu.SaveAsJpg);
    NFile.SaveAs->addAction(NFile.SaveAsMenu.SaveAsJpeg);


}

void NMenuBar::setupEdit()
{

}

void NMenuBar::setupHelp()
{
    NHelp.About = new QAction(tr("&About"));
    NHelp.TabletTest = new QAction(tr("&TabletTest"));

    nHelp->addAction(NHelp.About);
    nHelp->addSeparator();
    nHelp->addAction(NHelp.TabletTest);
}

void NMenuBar::setupConnection()
{
    connect(NFile.Open, &QAction::triggered, this, &NMenuBar::getFileName);
}

void NMenuBar::getFileName()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Open File"), "C:", tr("Image File(*png *jpg *jpeg)"));
    emit sendFileName(file);
}
