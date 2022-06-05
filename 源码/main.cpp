#include "mycomputer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyComputer w;
    w.show();

    return a.exec();
}
