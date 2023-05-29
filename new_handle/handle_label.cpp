#include"handle_label.h"







//输出位置信息
handlelabel::handlelabel(QWidget* parent):QLabel(parent)
{
    ispressed=true;
//设置背景图片
    this->setPixmap(QPixmap(":/picture/image/handle.png"));
    this->setFixedSize(QSize(250,250));
    this->setScaledContents(1);
    this->move(125,125);

    this->edgex=125;
    this->edgey=125;
    this->centerx=125;
    this->centery=125;



}

handlelabel::~handlelabel()
{

}
void handlelabel::movemouse()
{
    int xx=currx;
    int yy=curry;
    this->move(xx,yy);

}

bool handlelabel::isoutofrange(int currx, int curry, int edgex, int edgey, int centerx, int centery)
{
    //从侧边开始逆时针计算边界
    int y1=currx+edgex;
    int y2=edgex-currx;
    int y3=currx-edgex;
    int y4=-currx+3*edgex;
    if(curry<y1&&curry>y2&&curry>y3&&curry<y4)
    {
        return true;
    }
    return false;

}

void handlelabel::mouseMoveEvent(QMouseEvent *event)
{
    //event->setm
    //qDebug()<<"移动";
     currx=event->x();

     curry=event->y();
     if((event->buttons()&Qt::LeftButton)&&isoutofrange(currx, curry,  edgex, edgey,  centerx,  centery))
     {
         connect(timer,SIGNAL(timeout()),this,SLOT(movemouse()));
         timer->setInterval(10);
         timer->start();
         qDebug()<<"x: "<<currx<<"  "<<"y: "<<curry;
     }
//     else
//     {
//         qDebug()<<"wrong!";
//     }
}

//判断左键是否被按住
void handlelabel::mousePressEvent(QMouseEvent *event)
{
    //qDebug()<<"点击";
    currx=event->x();
    curry=event->y();
    if(event->button()==Qt::LeftButton&&event->type()==QEvent::MouseButtonPress&&isoutofrange(currx, curry,  edgex, edgey,  centerx,  centery))
    {
        timer=new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(movemouse()));
        timer->setInterval(1);
        timer->start();
    }
}
//判断左键是否被释放
void handlelabel::mouseReleaseEvent(QMouseEvent *event)
{
  //  qDebug()<<"释放";
    currx=event->x();
    curry=event->y();
    if(event->button()==Qt::LeftButton&&event->type()==QEvent::MouseButtonRelease)
    {
        this->move(centerx,centery);
    }
       // this->move(centerx,centery);

}
