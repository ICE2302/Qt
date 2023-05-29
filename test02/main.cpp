#include <QApplication>
#include"myclass.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myclass  m;
    m.show();
    return a.exec();
}

