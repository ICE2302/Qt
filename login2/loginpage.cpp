#include "loginpage.h"
#include<QSizePolicy>
loginpage::loginpage(QWidget *parent)
    : QMainWindow(parent)
{
//    QPushButton* btn=new QPushButton;
//    //设置父亲？
//     btn->setParent(this);
//     //设置文本
//     btn->setText("hello Qt，please click this button");
//     //move position
//      btn->setGeometry(100,100,100,100);
//     btn->move(100,100);

//     //second method
//     QPushButton * btn2=new QPushButton("second button",this);
//     //按钮和窗口都有setsize，应该是widget父类的方法


//     //set window title
//     this->resize(1000,500);
//     this->setWindowTitle("first project");
//     //restrain window size
//     this->setFixedSize(600,500);
//     QPushButton quit("Quit");
//     QWidget window;
//     //这三行是不正确的，因为看这创建对象的顺序看，其实在析构的时候是首先析构
//     //window，但是在创建的这个window之后，quit再设置window为父窗口，
    //这个时候可能window已经被析构了,因为quit是window的子窗口，那么quit也会被析构，而之后程序结束之后quit还会被析构一次
     //也就是说这种情况下，quit就会被析构两次
//      quit.setParent(&window);



    //输出按钮
//     QPushButton * quitBtn =new QPushButton("输入",this);
//     connect(quitBtn,SIGNAL(pressed()),this,SLOT(closeit()));

//报错
    this->setGeometry(0,0,1920,1080);//设置主窗口大小
    this->setWindowFlags(Qt::FramelessWindowHint);//隐藏标题栏
   //设置布局


    mainlayout=new QVBoxLayout();
    childlayout1=new QVBoxLayout();
    childlayout2=new QVBoxLayout();
    childlayout3=new QVBoxLayout();


    mainlayout->addLayout(childlayout1);
    mainlayout->addLayout(childlayout3);
    mainlayout->addLayout(childlayout2);
    mainlayout->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);

 initt();

     childlayout1->addWidget(system,Qt::AlignTop|Qt::AlignHCenter);
     childlayout2->addWidget(username);
     childlayout2->addWidget(passwd);
     childlayout2->addWidget(loginin);
     childlayout2->setAlignment(Qt::AlignVCenter|Qt::AlignHCenter);

     wholewindow->setLayout(mainlayout);




}
void loginpage::initt()
{
    wholewindow=new QLabel();
    wholewindow->setParent(this);
    wholewindow->setGeometry(0,0,1920,1080);

    wholewindow->setObjectName("wholewindow");

    //wholewindow->setPalette(*pattern3);
   wholewindow->setStyleSheet(
               "#wholewindow"
               "{border-image:url(:/picture/picture/bg.png); }"
               );
   wholewindow->setScaledContents(1);

    system=new QLabel("XXX软件模拟系统");
//    system->setParent(wholewindow);

    system->setStyleSheet("background-color:transparent;font-family:宋体;font-size:20px");


    username=new QLineEdit();
   // username->setParent(this);
     //username->setParent(wholewindow);
   username->setPlaceholderText("请输入用户名");//设置提示
    username->setAlignment(Qt::AlignVCenter);//水平居中
    username->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    username->setFixedSize(300,30);
   // username->setPalette(*pattern2);

    username->setStyleSheet("border-image:url(:/picture/picture/regularbg.png);font-family:宋体;font-size:16px;border-color: rgb(12, 196, 218);");

//    username->setFixedSize( QSize(140,40));


    passwd=new QLineEdit();
    passwd->setPlaceholderText("请输入密码");//设置提示
    passwd->setAlignment(Qt::AlignVCenter);//水平居中

    passwd->setStyleSheet("border-image:url(:/picture/picture/regularbg.png);font-family:宋体;font-size:16px;border-color: rgb(12, 196, 218);");

    passwd->setFixedSize( QSize(140,40));


    loginin=new QPushButton;
   // loginin->setParent(this);
    loginin->setText("输入");
   // loginin->setParent(wholewindow);
   // loginin->setPalette(*pattern1);

    loginin->setStyleSheet("border-image:url(:/picture/picture/bg1.png);font-family:宋体;font-size:16px;border-color: rgb(12, 196, 218);");

    passwd->setFixedSize( QSize(140,40));
    connect(loginin,SIGNAL(clicked()),this,SLOT(closeit()));



}

loginpage::~loginpage()
{
}
//点击输入关闭界面的槽函数
void loginpage::closeit()
{
    this->close();
}



