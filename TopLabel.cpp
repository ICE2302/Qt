#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
  //  , ui(new Ui::MainWindow)
{
    this->setGeometry(100,100,500,200);
    buttonvec.resize(size2);
    address1.resize(size1);
    address2.resize(size2);
    animation_vec.resize(size2);
    for(int i=0;i<size1;i++)
    {
        address1[i]=QPair<int,int>((i+1+i*size2)*width/count1,height/5);
    }
    QString str[7]={"任务部署","设备部署","批次信息","测量站远程控制","标定","教会测量","数据管理"};
    for(int i=0;i<size2;i++)
    {
        address2[i]=QPair<int,int>((i+1+i*size1)*width/count2,height/5);

        buttonvec[i]=new QPushButton(this);
        buttonvec[i]->setStyleSheet("border-image:url(:/duankuai.png);");
        buttonvec[i]->setText(str[i]);

        animation_vec[i]=new QPropertyAnimation(buttonvec[i]);;
        animation_vec[i]->setTargetObject(buttonvec[i]);
        group.addAnimation(animation_vec[i]);
    }
    buttonvec[0]->setGeometry(address2[0].first,address2[0].second,width*size1/count1,height/5);
    buttonvec[3]->setGeometry(address2[1].first,address2[1].second,width*size1/count1,height/5);
    buttonvec[4]->setGeometry(address2[2].first,address2[2].second,width*size1/count1,height/5);
    buttonvec[5]->setGeometry(address2[3].first,address2[3].second,width*size1/count1,height/5);
    buttonvec[6]->setGeometry(address2[4].first,address2[4].second,width*size1/count1,height/5);
    buttonvec[1]->setGeometry((1)*width/count1,height/5,0,height/5);
    buttonvec[2]->setGeometry((1)*width/count1,height/5,0,height/5);

    connect(buttonvec[0],SIGNAL(clicked()),this,SLOT(on_first_clicked()));
    for(int i=1;i<size2;i++)
    {
        connect(buttonvec[i],&QPushButton::clicked,this,[this](){presstime=0;});
    }

}
void MainWindow::on_first_clicked()
{
    presstime++;
    if(presstime%2==0&&presstime%4!=0)
    {
        for(int i=0;i<7;i++)
        {
            animation_vec[i]->setPropertyName("geometry");
            animation_vec[i]->setDuration(300);
            animation_vec[i]->setStartValue(buttonvec[i]->geometry());
            animation_vec[i]->setEndValue(QRect(address2[i].first,address2[i].second,width*5/43,height/5));
            animation_vec[i]->setEasingCurve(QEasingCurve::Linear);
        }
        group.start();
    }
    else if(presstime%4==0)
    {
        for(int i=0;i<7;i++)
        {
            //animation_vec[i]->setStartValue(QRect(address2[i].first,address2[i].second,width*7/count1,height/5));
            animation_vec[i]->setStartValue(buttonvec[i]->geometry());
        }
        animation_vec[0]->setEndValue(QRect(address2[0].first,address2[0].second,width*5/count1,height/5));
        animation_vec[3]->setEndValue(QRect(address2[1].first,address2[1].second,width*5/count1,height/5));
        animation_vec[4]->setEndValue(QRect(address2[2].first,address2[2].second,width*5/count1,height/5));
        animation_vec[5]->setEndValue(QRect(address2[3].first,address2[3].second,width*5/count1,height/5));
        animation_vec[6]->setEndValue(QRect(address2[4].first,address2[4].second,width*5/count1,height/5));
        animation_vec[1]->setEndValue(QRect((1)*width/count1,height/5,0,height/5));
        animation_vec[2]->setEndValue(QRect((1)*width/count1,height/5,0,height/5));

        group.start();
    }

}



MainWindow::~MainWindow()
{

}



