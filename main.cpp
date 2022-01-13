#include "termometro.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Termometro w;
    w.show();
    return a.exec();
}
