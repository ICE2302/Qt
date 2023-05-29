#include <QApplication>
#include "handle.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    handle w;
    w.show();
    return a.exec();
}
