#include "handle.h"
#include"QDebug"
double scale=0.4;
handle::handle(QLabel *parent,int r,double scale1) : QLabel(parent)
{
   r=300;//测试时给了个值，可调用时给值
   setFixedSize(r,r);
   //setMouseTracking(1);
   //this->setWindowFlags(Qt::Window|Qt::FramelessWindowHint);
   this->setStyleSheet("background:transparent;");
   lab1=new QLabel(this);
   lab1->setGeometry(0,0,this->width(),this->height());
   lab1->setPixmap(QPixmap(":/new/prefix1/di.png"));
   lab1->setScaledContents(1);
   //lab1->setMouseTracking(1);
   lab1->lower();
   lab2=new QLabel(this);
   lab2->setGeometry(this->width()*(1-scale)/2,this->width()*(1-scale)/2,this->width()*scale,this->height()*scale);
   lab2->setPixmap(QPixmap(":/new/prefix1/qiu.png"));
   lab2->setScaledContents(1);
   //lab2->setMouseTracking(1);
   pusleft=new QPushButton(lab1);
   pusleft->setGeometry(r*3/50,r*17/40,r*3/25,r*29/200);
   pusup=new QPushButton(lab1);
   pusup->setGeometry(r*17/40,r*3/50,r*29/200,r*3/25);
   pusdown=new QPushButton(lab1);
   pusdown->setGeometry(r*17/40,r*41/50,r*29/200,r*3/25);
   pusright=new QPushButton(lab1);
   pusright->setGeometry(r*41/50,r*17/40,r*3/25,r*29/200);

   tim=new QTimer(this);
   connect(pusleft,SIGNAL(clicked()),this,SLOT(leftu()));
   connect(pusup,SIGNAL(clicked()),this,SLOT(upu()));
   connect(pusdown,SIGNAL(clicked()),this,SLOT(downu()));
   connect(pusright,SIGNAL(clicked()),this,SLOT(rightu()));

   connect(tim, SIGNAL(timeout()), this, SLOT(getKeyNum()));

}

void handle::paintEvent(QPaintEvent *event)
{

        padR=lab1->width()/2;//底盘圆心
        handleR=lab2->width()/2;//摇杆圆半径
        padX=padR;//底盘圆心
        padY=padR;//底盘圆心
        int handleMaxR=padR-handleR;
        if(!mousePressed){//鼠标没按下则摇杆恢复到底盘中心
            mouseX=padX;
            mouseY=padY;
            lab2->move(mouseX-handleR,mouseY-handleR);
        }
        handPadDis=Pointdis(padR,padR,mouseX,mouseY);
        if(handPadDis<=handleMaxR){
            handleX=mouseX;
            handleY=mouseY;
            lab2->move(handleX-handleR,handleY-handleR);
        }
        else {
            handleX=(int)(handleMaxR*(mouseX-padX)/handPadDis+padX);
            handleY=(int)(handleMaxR*(mouseY-padY)/handPadDis+padY);
            lab2->move(handleX-handleR,handleY-handleR);
        }

}

void handle::mouseMoveEvent(QMouseEvent *event)
{
    static bool r=false;
    mouseX=event->pos().x();
    mouseY=event->pos().y();
    if(r==true){
        update();
        r=false;
    }
    else{
        r=true;
    }
}

void handle::mouseReleaseEvent(QMouseEvent *event)
{
    mouseX=width()*scale;
    mouseY=height()*scale;
    tim->stop();
    mousePressed=false;
    emit releasit();
    update();
    xs=0.0;//应该让释放后横纵坐标归零
    ys=0.0;

}

void handle::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton&&entermenu(event->pos(),lab1))
    {
    mouseX=event->pos().x();
    mouseY=event->pos().y();
    int k=Pointdis(padX,padY,mouseX,mouseY);

    if(k<padR)
    {
        tim->start(100);
        mousePressed=true;
        emit pressit();
        update();
    }
    }

}

double handle::Pointdis(int a, int b, int x, int y)
{
    return sqrt((double)((x-a)*(x-a)+(y-b)*(y-b)));
}

void handle::leftu()
{
    xs=xs-0.01;
    qDebug()<<xs;
}

void handle::upu()
{
    ys=ys+0.01;
    qDebug()<<ys;
}

void handle::downu()
{
    ys=ys-0.01;
    qDebug()<<ys;
}

void handle::rightu()
{
    xs=xs+0.01;
    qDebug()<<xs;
}

void handle::getKeyNum()
{
    if(Pointdis(mouseX,mouseY,padX,padY)<=padR)
    {
        xs=((double)mouseX-(double)padX)/(double)padR;
        ys=((double)padY-(double)mouseY)/(double)padR;
    }
    else
    {
        xs=((double)mouseX-(double)padX)/Pointdis(mouseX,mouseY,padX,padY);
        ys=((double)padY-(double)mouseY)/Pointdis(mouseX,mouseY,padX,padY);
    }
    qDebug()<<xs<<ys;
}
bool handle::entermenu(QPoint p,QLabel *l)
{
    int height = l->height();
    int width = l->width();
    QPoint btnMinPos = l->pos();
    QPoint btnMaxPos = l->pos();
    btnMaxPos.setX(l->pos().x()+width);
    btnMaxPos.setY(l->pos().y()+height);
    if(p.x() >= btnMinPos.x() && p.y() >= btnMinPos.y()
        && p.x() <= btnMaxPos.x() && p.y() <= btnMaxPos.y())
        return true;
    else
        return false;
}
