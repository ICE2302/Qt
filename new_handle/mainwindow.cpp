#include "mainwindow.h"
#include "ui_mainwindow.h"

//MainWindow::MainWindow(QWidget *parent)
//    : QMainWindow(parent)
//    , ui(new Ui::MainWindow)
//{
//    ui->setupUi(this);
//}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //this->setWindowFlags(Qt::FramelessWindowHint);
    this->setGeometry(100,100,500,500);
    init();



}

MainWindow::~MainWindow()
{
    //delete ui;
}



void MainWindow::init()
{
//    bglabel=new QLabel(this);
//    bglabel->setObjectName("bglabel");
//    bglabel->setStyleSheet("#bglabel{border-image:url(:/picture/image/bg.png);}");
//    bglabel->setGeometry(0,0,500,500);
//    bglabel->setScaledContents(1);
//    bglabel->setMouseTracking(true);

    bglabel=new QLabel(this);
    bglabel->setPixmap(QPixmap(":/picture/image/bg.png"));
    //bglabel->resize(bglabel->pixmap()->size());
    bglabel->setGeometry(0,0,500,500);
    bglabel->setScaledContents(1);
    //bglabel->setMouseTracking(true);

    handle=new handlelabel(bglabel);

}

//void MainWindow::mouseMoveEvent(QMouseEvent *event)
//{
//    handle->currx=event->x();
//    handle->curry=event->y();

//}




