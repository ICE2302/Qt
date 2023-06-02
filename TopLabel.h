#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMouseEvent>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVector>
#include<QPair>
#include<QDebug>
#include<QParallelAnimationGroup>
#include<QPropertyAnimation>
#include<QDebug>
/*
目标：设置一个长条间隔均匀的有彩虹的七种颜色，在打开时窗口中有五中颜色分别为赤绿青蓝紫，
点击红色之后，后面滑动出现橙色和黄色的色块，同时七种颜色的宽度随之变化调节成均匀的大小

  */

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:


private:
    QVector<QPushButton*> buttonvec;
    QVector<QPair<int,int>> address1;
    QVector<QPair<int,int>>address2;
    int size1=5;
    int size2=7;
    int count1=41;
    int count2=43;
    int width=500;
    int height=200;

    QVector<QPropertyAnimation*> animation_vec;
    QParallelAnimationGroup group;
    int presstime=0;
private slots:
    void on_first_clicked();
};
#endif // MAINWINDOW_H
