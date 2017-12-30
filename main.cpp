#include "nmainwindow.h"
#include <QApplication>
#include "NGadget/ntablettest.h"

int main(int argc, char *argv[])
{
    QApplication NeoApplication(argc, argv);
    NMainWindow NeoMainWindow;
    NeoMainWindow.setGeometry(100, 100, 1600, 900);
    NeoMainWindow.show();

    return NeoApplication.exec();
}
