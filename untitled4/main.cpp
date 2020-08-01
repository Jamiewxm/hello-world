#include "textfinder.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TextFinder w;
   // w.removeHat('A');
    w.show();
    return a.exec();
}
