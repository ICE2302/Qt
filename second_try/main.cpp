#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //下面这一行的代码也是必须的
    QApplication a(argc, argv);
    MainWindow w;
    //默认情况下，
    //Qt 提供的所有组件（控件、部件）都是隐藏的，不会自动显示。
    //通过调用 MainWindow 类提供的 show() 方法，w 窗口就可以在程序运行后显示出来。
    w.show();
    //下面一行的代码是必须的
    return a.exec();
}
