#include "nmenubar.h"
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QDebug>

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
    connect(NFile.SaveAsMenu.SaveAsPng, &QAction::triggered, this, &NMenuBar::getSaveFileName_PNG);
    connect(NFile.SaveAsMenu.SaveAsJpg, &QAction::triggered, this, &NMenuBar::getSaveFileName_JPG);
    connect(NFile.SaveAsMenu.SaveAsJpeg, &QAction::triggered, this, &NMenuBar::getSaveFileName_JPEG);
}

void NMenuBar::getFileName()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Open File"), "C:", tr("Image File(*png *jpg *jpeg)"));
    emit sendFileName(file);
}

void NMenuBar::getSaveFileName_PNG()
{
    QString file = QFileDialog::getSaveFileName(this, tr("Save as PNG"), "C:", tr("Image File(*png)"));
//    qDebug()<< file<< endl;
    emit sendSaveFileName(file);
}
void NMenuBar::getSaveFileName_JPG()
{
    QString file = QFileDialog::getSaveFileName(this, tr("Save as JPG"), "C:", tr("Image File(*jpg)"));
    emit sendSaveFileName(file);
}
void NMenuBar::getSaveFileName_JPEG()
{
    QString file = QFileDialog::getSaveFileName(this, tr("Save as JPEG"), "C:", tr("Image File(*jpeg)"));
    emit sendSaveFileName(file);
}
