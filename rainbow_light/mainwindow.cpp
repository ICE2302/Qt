#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //设置隐藏标题栏
   this->setWindowFlags(Qt::FramelessWindowHint);
   this->setGeometry(100,100,512+256+128,288+144+72);
    //设置圆角
   //this->setStyleSheet("border-radius: 30px;");
    //this->setStyleSheet("border-radius: 10px;");
   init();
}

MainWindow::~MainWindow()
{
    //delete ui;
}

//槽函数，变换颜色
void MainWindow::alter()
{
    //delete startlayout;

    window=new sonwindow(this);
   this->setCentralWidget(window);
    //window->raise();
     //window->show();
    //window->setWindowTitle("rainbow_light");
    //window->show();
}

//初始化窗口控件
void MainWindow::init()
{

    mainlabel=new QLabel();
    mainlabel->setParent(this);
    mainlabel->setObjectName("mainlabel");
    mainlabel->setStyleSheet("#mainlabel{border-image:url(:/picture/picture/wanye.jpg);}");
    mainlabel->setFixedSize(QSize(512+256+128,288+144+72));
    mainlabel->setScaledContents(1);

    start=new QPushButton("开始",mainlabel);
    start->setObjectName("start");
    start->setStyleSheet("#start{background-color:transparent;font-family:楷体;color:yellow;border:2px solid black;font-size:40px;font-weight:bold;text-align: center;border-radius: 10px;}");
    start->setParent(mainlabel);
    connect(start,SIGNAL(clicked()),this,SLOT(alter()));//跳转到彩虹灯界面afterlabel

    startlayout=new QVBoxLayout();
    startlayout->addStretch(1);
    startlayout->addWidget(start);
    startlayout->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);

    mainlabel->setLayout(startlayout);



}

