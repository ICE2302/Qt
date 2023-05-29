#include"sonwindow.h"


 sonwindow::sonwindow(QWidget *parent)
     : QWidget(parent)
{
    afterlayout=new QVBoxLayout();
    this->setGeometry(0,0,512+256+128,288+144+72);

    rainbow_color.resize(7);


    rainbow_color[0]=new QLabel();
    rainbow_color[0]->setStyleSheet("background-color: rgb(238, 39, 4);");


    rainbow_color[1]=new QLabel();
    rainbow_color[1]->setStyleSheet("background-color: rgb(255, 85, 0);");

    rainbow_color[2]=new QLabel();
    rainbow_color[2]->setStyleSheet("  background-color: rgb(255, 255, 0);");

    rainbow_color[3]=new QLabel();
    rainbow_color[3]->setStyleSheet("  background-color: rgb(0, 255, 0);");

    rainbow_color[4]=new QLabel();
    rainbow_color[4]->setStyleSheet("background-color: rgb(85, 170, 255);");

    rainbow_color[5]=new QLabel();
    rainbow_color[5]->setStyleSheet("background-color: rgb(0, 85, 255);");

    rainbow_color[6]=new QLabel();
    rainbow_color[6]->setStyleSheet("background-color: rgb(170, 85, 255);");



    rainbow_color[0]->setFixedSize(512+256+128,72);
    rainbow_color[1]->setFixedSize(512+256+128,72);
    rainbow_color[2]->setFixedSize(512+256+128,72);
    rainbow_color[3]->setFixedSize(512+256+128,72);
    rainbow_color[4]->setFixedSize(512+256+128,72);
    rainbow_color[5]->setFixedSize(512+256+128,72);
    rainbow_color[6]->setFixedSize(512+256+128,72);


     afterlayout->addWidget(rainbow_color[0],1,Qt::AlignVCenter);
     afterlayout->addWidget(rainbow_color[1],2,Qt::AlignVCenter);
     afterlayout->addWidget(rainbow_color[2],3,Qt::AlignVCenter);
     afterlayout->addWidget(rainbow_color[3],1,Qt::AlignVCenter);
     afterlayout->addWidget(rainbow_color[4],1,Qt::AlignVCenter);
     afterlayout->addWidget(rainbow_color[5],1,Qt::AlignVCenter);
     afterlayout->addWidget(rainbow_color[6],1,Qt::AlignVCenter);
     //afterlayout->setAlignment(Qt::AlignVCenter);
     //qDebug() << this->layout();

     afterlayout->setSpacing(0);
     afterlayout->setMargin(0);
     this->setLayout(afterlayout);

     timer=new QTimer();
     connect(timer,SIGNAL(timeout()),this,SLOT(process()));
     timer->setInterval(50);
     timer->start();

}

 void sonwindow::process()
 {
     static qlonglong timesec=0;//必须是静态

     //qDebug("执行process");
     //qDebug()<<timesec;
         switch(++timesec%=7)
         {
             case 0:
             {
                 afterlayout->removeWidget(rainbow_color[timesec]);
                 afterlayout->addWidget(rainbow_color[timesec]);
                 break;
             }
             case 1:
             {
                 afterlayout->removeWidget(rainbow_color[timesec]);
                 afterlayout->addWidget(rainbow_color[timesec]);
                 break;
             }
             case 2:
             {
                 afterlayout->removeWidget(rainbow_color[timesec]);
                 afterlayout->addWidget(rainbow_color[timesec]);
                 break;
             }
             case 3:
             {
                 afterlayout->removeWidget(rainbow_color[timesec]);
                 afterlayout->addWidget(rainbow_color[timesec]);
                 break;
             }
             case 4:
             {
                 afterlayout->removeWidget(rainbow_color[timesec]);
                 afterlayout->addWidget(rainbow_color[timesec]);
                 break;
             }
             case 5:
             {
                 afterlayout->removeWidget(rainbow_color[timesec]);
                 afterlayout->addWidget(rainbow_color[timesec]);
                 break;
             }
             case 6:
             {
                 afterlayout->removeWidget(rainbow_color[timesec]);
                 afterlayout->addWidget(rainbow_color[timesec]);
                 break;
             }
         default:{}
         }
        // qDebug("执行stop");
 }



 sonwindow::~sonwindow()
 {

 }
