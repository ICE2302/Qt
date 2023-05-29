#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(100,100,500,500);
    init();
    //ui->setupUi(this);
}
void MainWindow::init()
{
    bg=new QLabel(this);
    bg->setPixmap(QPixmap(":/image/bg.png"));
    bg->setScaledContents(1);
    bg->setGeometry(0,0,500,500);

    handle=new QLabel(bg);
    handle->setPixmap(QPixmap(":/image/handle.png"));
    handle->setScaledContents(1);

    //设置handle的尺寸
    edge=bg->geometry().width()/4;
    handle->setFixedSize(QSize(edge,edge));
    //设置handle在中心位置
    centerx=bg->geometry().center().x()-handle->size().width()/2;
    centery=bg->geometry().center().y()-handle->size().height()/2;

    handlepoint=new QPoint(centerx,centery);
    handle->move(*handlepoint);

    //定时器
    timer=new QTimer();
//    connect(timer,SIGNAL(timeout()),this,SLOT(record()));
//    timer->setInterval(100);
//    timer->start();

}

bool MainWindow::isin()
{
    int ccx=handle->geometry().x();
    int ccy=handle->geometry().y();
    int y1=ccy;
    int x2=ccx+edge;
    int y3=ccy+edge;
    int x4=ccx;
    if(currx<x2&&currx>x4&&curry<y3&&curry>y1)return true;
    return false;


}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    currx=event->x();
    curry=event->y();

//    connect(timer,SIGNAL(timeout()),this,SLOT(record()));
//    timer->setInterval(100);
//    timer->start();

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    currx=event->x();
    curry=event->y();
    handle->move(centerx,centery);



}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
        currx=event->x();
        curry=event->y();


       //定时器
//        connect(timer,SIGNAL(timeout()),this,SLOT(record()));
//        timer->setInterval(1);
//        timer->start();
        //确定鼠标是否在handle中
        record();
        if(isin())
        {
             qDebug()<<"x: "<<currx<<"  y: "<<curry;
        }
//        else
//        {
//            qDebug()<<"x: "<<xx <<"  y:"<<yy;
//        }
        //确定鼠标控制的handle不超过窗口边界
        // 计算子控件的新坐标
//        int xx=event->x();
//        int yy=event->y();
        int xx=handle->geometry().x();
        int yy=handle->geometry().y();
        // 限制子控件的坐标
        if(xx<0)
        {
            xx=0;
        }
        else if(bg->geometry().width()-edge<xx)
        {
            xx=bg->geometry().width()-edge;
        }
        if(yy<0)
        {
            yy=0;
        }
        else if(bg->geometry().height()-edge<yy)
        {
            yy=bg->geometry().height()-edge;
        }
        // 移动子控件
        handle->setGeometry(xx,yy,edge,edge);
        qDebug()<<"handle"<<xx<<" "<<yy;
        qDebug()<<"鼠标"<<event->x()<<" "<<event->y();
}
MainWindow::~MainWindow()
{
    //delete ui;
}

void MainWindow::record()
{

    if(isin())
    {
        handle->move(currx-edge/2,curry-edge/2);
//        qDebug()<<"x: "<<currx<<"  y: "<<curry;
    }
//    else
//    {
//        qDebug()<<"Wrong !";
//    }



}

