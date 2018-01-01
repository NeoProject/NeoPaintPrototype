#ifndef NMENUBAR_H
#define NMENUBAR_H

#include <QObject>
#include <QMenuBar>
#include <QWidget>

class QMenu;
class QAction;

class NMenuBar : public QMenuBar
{
    Q_OBJECT

public:
    NMenuBar(QWidget *parent = 0);

public:
    QMenu *nFile;
    QMenu *nEdit;
    QMenu *nHelp;

    struct FILE
    {
        QAction *Open;
        QAction *Save;
        QMenu *SaveAs;

        struct SAVEASMENU
        {
            QAction *SaveAsPng;
            QAction *SaveAsJpg;
            QAction *SaveAsJpeg;
        }SaveAsMenu;

        QAction *Close;
    }NFile;

    struct EDIT
    {
        QAction *Undo;
        QAction *Redo;
    }NEdit;

    struct HELP
    {
        QAction *About;
        QAction *TabletTest;
    }NHelp;

private slots:
    void getFileName();

signals:
    void sendFileName(const QString &file);

private:
    void setupSelf();
    void setupFile();
    void setupEdit();
    void setupHelp();

    void setupConnection();

};

#endif // NMENUBAR_H
