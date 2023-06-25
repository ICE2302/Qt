#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //创建一个Qlabel对象
    this->lab=new QLabel("Hello Qt",this);

}

MainWindow::~MainWindow()
{
}

