#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include<QMouseEvent>
#include<QTimer>
#include<math.h>
#include<QDebug>
#include<QRect>
#include<QPoint>

QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:

private slots:
    void record();//记录鼠标在父控件中的位置，使handle移动到这个位置上

private:
    QLabel* bg;
    QLabel * handle;
    //初始化数据
    void init();

    //判断当前坐标是否在handle中，使用直线方程
    bool isin();//需要获取handle在父控件中的位置，这个是动态获取的
    int currx;//记录鼠标在父控件中的位置
    int curry;

    int centerx;//记录父控件的中心位置，也就是设置handle将要在的中心位置
    int centery;
    int edge;//记录子控件的边界
    //设置handle的位置
    QPoint* handlepoint;

    //定时器
    QTimer * timer;


    //松开鼠标，handle复位
    //点击鼠标，记录鼠标相对于handle的位置currx,curry.可能要切换坐标系
    //拖拽鼠标设置
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

    //Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
