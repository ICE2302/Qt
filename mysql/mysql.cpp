#include "mysql.h"

Mysql::Mysql(QWidget *parent)
    : QWidget(parent)
{

    conn();
    init();
}

Mysql::~Mysql()
{

}


void Mysql::conn()
{
    sqlname="root";
    sqlpasswd="123456";
    hostname="localhost";
    dbname="bak_db";
    db.setPort(3306);
    db.setHostName(hostname);
    db.setPassword(sqlpasswd);
    db.setUserName(sqlname);
    db.setDatabaseName(dbname);
    if(db.open())
    {
        qDebug()<<"success!";
    }
    else {qDebug()<<"failed!";}
   // db.close();

}

void Mysql::init()
{
    this->setFixedSize(1000,1000);
    table=new QTableWidget(this);
    table->move(20,200);
    table->setFixedSize(500,500);
    QStringList headers;
    headers << "id" << "用户名" << "密码"<<"权限";
    table->setColumnCount(4);
    table->setHorizontalHeaderLabels(headers);

    inputinfo=new QLineEdit(this);
    inputinfo->setPlaceholderText("请输入姓名 / 权限");
    inputinfo->move(20,50);

    findname=new QPushButton("按姓名查询",this);
    findname->move(180,30);
    connect(findname,&QPushButton::clicked,[this](){
        QString name=inputinfo->text();
        if(find_byname(name))
        {
            flush_data(userinfo);
            userinfo.clear();
        }else  QMessageBox::critical(nullptr, "错误", "something wrong!", QMessageBox::Retry);
    });

     findpermission=new QPushButton("按权限查询",this);
     findpermission->move(180,70);
     connect(findpermission,&QPushButton::clicked,[this](){
         QString name=inputinfo->text();
         if(find_bypermission(name))
         {
             flush_data(userinfo);
             userinfo.clear();
         }
        else QMessageBox::critical(nullptr, "错误", "something wrong!", QMessageBox::Retry);
     });

     inputdelinfo=new QLineEdit(this);
     inputdelinfo->setPlaceholderText("请输入姓名 / 权限");
     inputdelinfo->move(280,50);

     delname=new QPushButton("按姓名删除",this);
     delname->move(440,30);
     connect(delname,&QPushButton::clicked,[this](){
         QString name=inputinfo->text();
         if(del_byname(name))
         {
             flush_data(userinfo);
             userinfo.clear();
         }else  QMessageBox::critical(nullptr, "错误", "something wrong!", QMessageBox::Retry);
     });

     delpermission=new QPushButton("按权限删除",this);
     delpermission->move(440,70);
     connect(delpermission,&QPushButton::clicked,[this](){
         QString name=inputinfo->text();
         if(del_bypermission(name))
         {
             flush_data(userinfo);
             userinfo.clear();
         }else  QMessageBox::critical(nullptr, "错误", "something wrong!", QMessageBox::Retry);
     });

     addinfo=new QPushButton("添加信息",this);
     addinfo->move(440,100);
     connect(addinfo,&QPushButton::clicked,[this](){
         if(adduserinfo(user->text(),passwd->text(),permission->text()))
         {
             flush_data(userinfo);
         }
     });

     updateinfo=new QPushButton("修改信息",this);
     updateinfo->move(440,130);
     connect(updateinfo,&QPushButton::clicked,[this](){
         if(updateuserinfo(user->text(),passwd->text(),permission->text()))
         {
             flush_data(userinfo);
         }
     });

     user=new QLineEdit(this);
     user->move(20,120);
     user->setPlaceholderText("请输入用户名");

     passwd=new QLineEdit(this);
     passwd->move(160,120);
     passwd->setPlaceholderText("请输入密码");

     permission=new QLineEdit(this);
     permission->move(300,120);
     permission->setPlaceholderText("请输入权限(1/2)");

     all=new QPushButton("查看所有信息",this);
     all->move(20,160);
     connect(all,&QPushButton::clicked,[this](){
         findall();
         flush_data(userinfo);
     });
    findall();
    flush_data(userinfo);
}

bool Mysql::isuser(QString username, QString password)
{
    QSqlQuery query1(db),query2(db);
    query1.prepare("select * from  users where username=:username "
                   "and password=:password and permission=1;");//查询是否为管理员
    query1.bindValue(":username",username);
    query1.bindValue(":password",password);

    query2.prepare("select * from  users where username=:username,"
                  "and password=:password and permission=2;");//查询是否为普通职员
    query2.bindValue(":username",username);
    query2.bindValue(":password",password);

    if (query1.exec()) {
        isAdmin=true;
        qDebug()<<"管理员登陆成功";
        return true;
    }
    else if(query2.exec())
    {
        isAdmin=false;
        qDebug()<<"普通职员登陆成功";
        return true;
    }
    else
     {
        qDebug()<<"用户名或密码错误！";
    }
    return false;

}
void Mysql::flush_data(QVector<QVector<QString>>&userinfo)
{
    table->clear();
    if(!userinfo.size())return;
    table->setRowCount(userinfo.size());
    table->setColumnCount(4);
    for(int i=0;i<userinfo.size();i++)
    {
        for(int j=0;j<userinfo[0].size();j++)
        {
            table->setItem(i,j,new QTableWidgetItem(userinfo[i][j]));
        }
    }
     table->setHorizontalHeaderLabels({"id","用户名","密码","权限"});
}
void Mysql::findall()
{
    userinfo.clear();
    QSqlQuery query(db);
    query.prepare("select * from users;");
    if(query.exec())
    {
         while (query.next()) {
             QVector<QString>rec;
             for(int i=0;i<query.record().count();i++)
             {
                 rec.push_back(query.record().value(i).toString());
             }
             userinfo.push_back(rec);
         }
    }
}

bool Mysql::find_byname(QString name)
{
    userinfo.clear();
    QSqlQuery query(db);
        query.prepare("select * from users where username=:name;");
        query.bindValue(":name",name);
        if(query.exec())
        {
             while (query.next()) {
                 QVector<QString>rec;

                 rec.push_back(query.record().value("id").toString());
                 rec.push_back(query.record().value("username").toString());
                 rec.push_back(query.record().value("password").toString());
                 rec.push_back(query.record().value("permission").toString());

                 userinfo.push_back(rec);
             }
             return true;
        }
            return false;
}

bool Mysql::find_bypermission(QString permissionn)
{
    userinfo.clear();
    QSqlQuery query(db);
        query.prepare("select * from users where permission=:permission;");
        query.bindValue(":permission",permissionn);

        if(query.exec())
        {
             while (query.next()) {
                 QVector<QString>rec;
                 rec.push_back(query.record().value("id").toString());
                 rec.push_back(query.record().value("username").toString());
                 rec.push_back(query.record().value("password").toString());
                 rec.push_back(query.record().value("permission").toString());
                 userinfo.push_back(rec);
             }
             return true;
        }
        return false;
}

bool Mysql::adduserinfo(QString user, QString passwd, QString per)
{
    QSqlQuery query(db);
    query.prepare("insert into users(username,password,permission) values(:user,:passwd,:per);");
    query.bindValue(":user",user);
    query.bindValue(":passwd",passwd);
    query.bindValue(":per",per);
    if(query.exec())
    {
        findall();
        return true;
    }
    return false;
}

bool Mysql::updateuserinfo(QString user, QString passwd, QString per)
{
    QSqlQuery query(db);
    query.prepare("UPDATE users SET username=:user, password=:passwd ,permission=:per WHERE  username=:user;");
    query.bindValue(":user",user);
    query.bindValue(":passwd",passwd);
    query.bindValue(":per",per);
    if(query.exec())
    {
        findall();
        return true;
    }
    return false;
}

bool Mysql::del_byname(QString name)
{
    QSqlQuery query(db);
    query.prepare("delete from users WHERE  username=:user;");
    query.bindValue(":user",name);
    if(query.exec())
    {
        findall();
        return true;
    }
    return false;
}

bool Mysql::del_bypermission(QString permissionn)
{
    QSqlQuery query(db);
    query.prepare("delete from users WHERE  permission=:permission");
    query.bindValue(":permission",permissionn);
    if(query.exec())
    {
        findall();
        return true;
    }
    return false;
}

