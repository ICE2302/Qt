#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QWidget>
#include<QSql>
#include<QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlRecord>
#include <QSettings>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include<QMessageBox>
QT_BEGIN_NAMESPACE
QT_END_NAMESPACE

class Mysql : public QWidget
{
    Q_OBJECT

public:
    Mysql(QWidget *parent = nullptr);
    ~Mysql();
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    QString sqlname,hostname,sqlpasswd,dbname,sqlport;
    //查
    QPushButton* findname;
    QPushButton* findpermission;
    QLineEdit* inputinfo;
    //增
    QPushButton* addinfo;
    QLineEdit* user,*passwd,*permission;
    //改
    QPushButton* updateinfo;
    //删
    QPushButton* delname;
    QPushButton* delpermission;
    QLineEdit* inputdelinfo;
    QVector<QVector<QString>>userinfo;
    QTableWidget* table;
    QPushButton* all;
    //建立连接
    void conn();
    void init();
    //登录
    bool isAdmin;//判断是否是管理员
    bool isuser(QString username,QString password);
    void findall();//查看所有用户
    void flush_data(QVector<QVector<QString>>&userinfo);
    bool find_byname(QString name);
    bool find_bypermission(QString permission);
    bool adduserinfo(QString user,QString passwd,QString per);
    bool updateuserinfo(QString user,QString passwd,QString per);
    bool del_byname(QString name);
    bool del_bypermission(QString permissionn);



private:

};
#endif // MAINWINDOW_H
