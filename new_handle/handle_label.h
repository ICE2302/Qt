#ifndef HANDLE_LABEL_H
#define HANDLE_LABEL_H
#include<QLabel>
#include<QWidget>
#include<QMouseEvent>
#include<QDebug>
#include<QTimer>
 class handlelabel : public QLabel
{
    Q_OBJECT
public:
    handlelabel(QWidget* parent=NULL) ;
    virtual ~handlelabel() ;

 signals:
private slots:
    void  movemouse();

 public:
    //关于测试越界
    int currx,curry,edgex,edgey,centerx,centery;
    bool isoutofrange(int currx,int curry,int edgex,int edgey,int centerx,int centery);



    bool ispressed;
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent* event);

    //定义定时器
    QTimer *timer;

};

#endif // HANDLE_LABEL_H
