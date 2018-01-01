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
    QMenu *nOption;
    QMenu *nHelp;

    struct FILE
    {
        QAction *New;
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

    struct OPTION
    {
        QAction *Settings;
    }NOption;

    struct HELP
    {
        QAction *About;
        QAction *TabletTest;
    }NHelp;

private slots:
    void getFileName();
    void getSaveFileName_PNG();
    void getSaveFileName_JPG();
    void getSaveFileName_JPEG();

signals:
    void sendFileName(const QString &file);
    void sendSaveFileName(const QString &file);

private:
    void setupSelf();
    void setupFile();
    void setupEdit();
    void setupOption();
    void setupHelp();

    void setupConnection();

};

#endif // NMENUBAR_H
