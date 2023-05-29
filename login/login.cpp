#include "login.h"
//#include <libpq-fe.h>

typedef QMap<QString, QVariant> MStr;// 存放查询条件和单条数据
typedef QVector<MStr> VMStr;// 保存查询结果
QString strss[12];
login::login(QWidget *parent) : QMainWindow(parent)
{
    setWindowFlag(Qt::FramelessWindowHint);
    setMouseTracking(true);
    this->setGeometry(0,0,1920,1080);
    init();
    dbsql dba;
//数据库操作
    if(!dba.connectToMysql("127.0.0.1",5432,"kaibo","postgres","123"))                                   //打开数据库
    {

        qDebug() << "saef";

    }
    else
    {
        if(dba.readtable("login")==true)
        {
            dba.deletable("login");
            qDebug()<<"success";
            dba.creattable("login");
            dba.insertRecord("login","communication","123","c");
            dba.insertRecord("login","radar","123","r");
            dba.insertRecord("login","sar","123","s");
            dba.insertRecord("login","disturb","123","d");
            dba.readRecord("login",strss);
            qDebug()<<strss;
        }
        else
        {
            qDebug()<<"success";
            dba.creattable("login");
            dba.insertRecord("login","communication","123","c");
            dba.insertRecord("login","radar","123","r");
            dba.insertRecord("login","sar","123","s");
            dba.insertRecord("login","disturb","123","d");
            dba.readRecord("login",strss);
            qDebug()<<strss;
        }
    }

}
/**
  * @brief
  * @param 初始化
  * @author chang
  * @date  20220826
  */
void login::init()
{
    mainlable=new QLabel(this);
    mainlable->setGeometry(0,0,1920,1080);
    //添加资源
    mainlable->setPixmap(QPixmap(":/new/prefix1/login/bg.png"));
    mainlable->setScaledContents(1);

    title=new QLabel(mainlable);
    title->setGeometry(708,153,459,51);
    title->setStyleSheet("color:rgb(12, 196, 218);");
    title->setFont(QFont("ALgerian",38,75));


    title->setText("XXX模拟系统软件");

    general_con=new QLabel(mainlable);
    general_con->setGeometry(110,349,300,224);
    communica_con=new QLabel(mainlable);
    communica_con->setGeometry(463,349,300,224);
    radar_con=new QLabel(mainlable);
    radar_con->setGeometry(815,349,300,224);
    sar_con=new QLabel(mainlable);
    sar_con->setGeometry(1168,349,300,224);
    disturb_con=new QLabel(mainlable);
    disturb_con->setGeometry(1520,349,300,224);
    draw_pics();


    zongkonglable=new QLabel(mainlable);
    zongkonglable->setGeometry(213,581,101,31);
    zongkonglable->setStyleSheet("color:rgb(255,255,255);""font:17pt 'Microsoft YaHei';");
    zongkonglable->setText("总控系统");

    tongxinlable=new QLabel(mainlable);
    tongxinlable->setGeometry(565,581,101,31);
    tongxinlable->setStyleSheet("color:rgb(255,255,255);""font:17pt 'Microsoft YaHei';");
    tongxinlable->setText("通信系统");

    leidalable=new QLabel(mainlable);
    leidalable->setGeometry(916,581,101,31);
    leidalable->setStyleSheet("color:rgb(255,255,255);""font:17pt 'Microsoft YaHei';");
    leidalable->setText("雷达系统");

    sarlable=new QLabel(mainlable);
    sarlable->setGeometry(1270,581,101,31);
    sarlable->setStyleSheet("color:rgb(255,255,255);""font:17pt 'Microsoft YaHei';");
    sarlable->setText("SAR系统");

    ganraolable=new QLabel(mainlable);
    ganraolable->setGeometry(1623,581,101,31);
    ganraolable->setStyleSheet("color:rgb(255,255,255);""font:17pt 'Microsoft YaHei';");
    ganraolable->setText("干扰系统");

    user=new QLineEdit(mainlable);
    user->setGeometry(812,736,298,44);
    passy=new QLineEdit(mainlable);
    passy->setGeometry(812,807,298,44);
    user->setStyleSheet("font: 87 16pt 'Arial Black';border-color: rgb(12, 196, 218);");
    passy->setStyleSheet("font: 87 16pt 'Arial Black';border-color: rgb(12, 196, 218);");
    passy->setEchoMode(QLineEdit::Password);

    user->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z0-9][a-zA-Z0-9.-]+$")));
    user->setPlaceholderText("请输入用户名：");//背景提示用户输入范围

    passy->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z0-9]+$")));
    passy->setPlaceholderText("请输入密码：");//背景提示用户输入范围

    user->setMaxLength(15);//限制输入长度,最大为128
    passy->setMaxLength(15);

    passy->setContextMenuPolicy(Qt::NoContextMenu);
    passy->setMouseTracking(1);

    logins=new QPushButton(mainlable);
    logins->setGeometry(812,878,299,44);

    logins->setStyleSheet("background-image: url(:/new/prefix1/login/denglu.png);border:none;color: rgb(255, 255, 255);color:rgb(255,255,255);font:18pt 'Agency FB';");
    logins->setText("登 录");

    connect(logins,SIGNAL(clicked()),this,SLOT(log_in()));
    connect(user,SIGNAL(textChanged(QString)),this,SLOT(mode_select(QString)));
}
/**
  * @brief
  * @param 模式切换
  * @author chang
  * @date  20220826
  */
void login::draw_pics()
{
    general_con->setPixmap(QPixmap(":/new/prefix1/login/zongkongh.png"));
    general_con->setScaledContents(1);

    communica_con->setPixmap(QPixmap(":/new/prefix1/login/tongxinh.png"));
    communica_con->setScaledContents(1);

    radar_con->setPixmap(QPixmap(":/new/prefix1/login/leidah.png"));
    radar_con->setScaledContents(1);

    sar_con->setPixmap(QPixmap(":/new/prefix1/login/ganraoh.png"));
    sar_con->setScaledContents(1);

    disturb_con->setPixmap(QPixmap(":/new/prefix1/login/sarh.png"));
    disturb_con->setScaledContents(1);
}
/**
  * @brief
  * @param  进入相应模式
  * @author chang
  * @date  20220826
  */
void login::log_in()
{
    QDesktopWidget *desktop = QApplication::desktop();//让应用窗口定位在屏幕上
    int	deskIndex = desktop->primaryScreen();
    QRect screenGeometry = desktop->screenGeometry();
    QRect screenGeometry1 = desktop->screenGeometry(deskIndex+1);
    QRect screenGeometry0 = desktop->screenGeometry(deskIndex);
    //屏2高度1080
    int scr1Height = screenGeometry1.height();
    //屏2宽度2560
    int scr1Width = screenGeometry1.width();
    if(user==NULL||passy==NULL)
    {
        QMessageBox::warning(this, "warning", "请输入用户名密码", QMessageBox::Ok);
    }
    else
    {
        int k=0;
        for (int i=0;i<4;i++)
        {
            QString a[3];
            a[0]=strss[i*3];
            a[1]=strss[1+i*3];
            a[2]=strss[2+i*3];
            if(user->text()==a[0]&&passy->text()==a[1])
            {
                if(a[2]=="s")
                {

        //            w->setGeometry(screenGeometry0);
        //            m->setGeometry(screenGeometry1);
        //            w->show();
        //            m->show();
                }
               else if(a[2]=="c")
                {
                    qDebug()<<"ok";
                }
               else if(a[2]=="r")
                {

                }
                else if(a[2]=="d")
                {

                }
#pragma region 延迟隐藏以解决页面切换时的闪烁问题
                QTime dieTime = QTime::currentTime().addMSecs(5);//5为延迟时间，可更改
                while (QTime::currentTime() < dieTime)
                    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
#pragma endregion
                this->close();
            }
            else
            {
                k--;
                if(k==-4)
                {
                  QMessageBox::warning(this, "warning", "用户名或密码错误", QMessageBox::Ok);
                }
            }
        }
    }
}
/**
  * @brief
  * @param 模式选择
  * @author chang
  * @date  20220826
  */
void login::mode_select(QString str)
{
    str=user->text();
    if(user==NULL)
    {
        return;
    }
    else
    {
        if(str[0]=="s")
        {
            draw_pics();
            sar_con->setPixmap(QPixmap(":/new/prefix1/login/ganrao.png"));
        }

        else
        {
            draw_pics();
        }
    }
}
/**
  * @brief
  * @param 按键功能预留
  * @author chang
  * @date  20220826
  */
void login::keyPressEvent(QKeyEvent *event)
{

}
