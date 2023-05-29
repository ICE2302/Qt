#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0,0,1920,1080);//设置主窗口大小
    this->setWindowFlags(Qt::FramelessWindowHint);//隐藏标题栏



   init();

   mainlayout=new QVBoxLayout();
   mainlayout->addWidget(syslabel,7,Qt::AlignHCenter|Qt::AlignTop);
   mainlayout->addSpacing(60);
   mainlayout->addWidget(username,1,Qt::AlignHCenter);
   mainlayout->addWidget(passwd,1,Qt::AlignHCenter);
   mainlayout->addWidget(loginbtn,1,Qt::AlignCenter);
   mainlayout->addSpacing(40);


   label->setLayout(mainlayout);



}


MainWindow::~MainWindow()
{
}

void MainWindow::init()
{
     label=new QLabel(this);
     label->setObjectName("label");
     label->setStyleSheet("#label{border-image:url(:/picture/picture/bg.png);}");
     label->setGeometry(0,0,1920,1080);
     label->setScaledContents(1);

     syslabel=new QLabel("XXX模拟系统");
     syslabel->setStyleSheet("background-color:transparent;font-family:楷体;font-size:30px;font-weight:bold;text-align: center;");
     syslabel->setFixedSize(QSize(400,300));
     syslabel->setAlignment(Qt::AlignCenter);
     syslabel->setFixedSize(QSize(600,600));

     username=new QLineEdit();
     username->setPlaceholderText("请输入用户名");
     username->setFixedSize(QSize(240,40));
     username->setStyleSheet("border-image:url(:/picture/picture/regularbg.png);font-family:宋体;font-size:16px;border-color: rgb(12, 196, 218);");

     passwd=new QLineEdit();
     passwd->setPlaceholderText("请输入密码");
     passwd->setFixedSize(QSize(240,40));
     passwd->setStyleSheet("border-image:url(:/picture/picture/regularbg.png);font-family:宋体;font-size:16px;border-color: rgb(12, 196, 218);");

     loginbtn=new QPushButton("登录");
     loginbtn->setStyleSheet("border-image:url(:/picture/picture/bg1.png);font-family:宋体;font-size:16px;border-color: rgb(12, 196, 218);");
     loginbtn->setFixedSize(QSize(240,40));
     connect(loginbtn,SIGNAL(clicked()),this,SLOT(closeit()));

}

void MainWindow::closeit()
{
    this->close();
}

