#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QDesktopWidget>
#include <QRect>
#include<QtDebug>
#include<QPoint>
#include<QIntValidator>
#include<QKeyEvent>
#include<QMessageBox>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QApplication>
#include<QTime>
#include<QtDebug>
#include"dbsql.h"
class login : public QMainWindow
{

    Q_OBJECT
public:
    explicit login(QWidget *parent = nullptr);

signals:
private:
    QLabel *mainlable;
    QLabel *title;

    QLabel *general_con;
    QLabel *communica_con;
    QLabel *radar_con;
    QLabel *sar_con;
    QLabel *disturb_con;
    QLabel *zongkonglable;
    QLabel *tongxinlable;
    QLabel *leidalable;
    QLabel *sarlable;
    QLabel *ganraolable;


    QPushButton *logins;
    QLineEdit *user;
    QLineEdit *passy;
public:

private:
    void init();
    virtual void keyPressEvent(QKeyEvent *event)override;
    void draw_pics();
private slots:
    void log_in();//登入
    void mode_select(QString);//模式选择

};

#endif // LOGIN_H
