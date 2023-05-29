#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QMainWindow>
#include<QSize>
#include<QLabel>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QPushButton>
#include<QPalette>
#include<QPageLayout>

class loginpage : public QMainWindow
{
    Q_OBJECT

public:
    loginpage(QWidget *parent = nullptr);
    ~loginpage();
  signals:

private:
    void initt();
//    //如果链接了数据库，那么就可以使用login验证登录了
//    void loginn();

private:
    QLabel * wholewindow;//覆盖在主窗口的背景
    QPushButton* loginin;//登录的按钮，跳转到退出
    QLineEdit* username;//输入用户名
    QLineEdit* passwd;//输入密码

    //添加系统标签
    QLabel * system;
    //添加布局
    QVBoxLayout* mainlayout;
    QVBoxLayout* childlayout1;//系统的布局
    QVBoxLayout* childlayout2;//输入的子布局
     QVBoxLayout* childlayout3;//中间空出来的布局



//槽函数的命名方式
private slots:
void closeit();
};
#endif // LOGINPAGE_H
