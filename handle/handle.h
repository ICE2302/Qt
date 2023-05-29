#ifndef HANDLE_H
#define HANDLE_H

#include <QPainter>
#include <QDrag>
#include <QMouseEvent>
#include <QtMath>
#include <QTimer>
#include<QLabel>
#include<QPushButton>
class handle : public QLabel
{
    Q_OBJECT
public:
    explicit handle(QLabel *parent = nullptr,int x=0,double ss=0.0);
protected:
    void paintEvent(QPaintEvent *event)override;
    void mouseMoveEvent(QMouseEvent *event)override;
    void mouseReleaseEvent(QMouseEvent *event)override;
    void mousePressEvent(QMouseEvent *event)override;
signals:
    void pressit();
    void releasit();
private:
    double Pointdis(int a,int b,int x,int y);//两点距离
    bool entermenu(QPoint p,QLabel *l);
private:
    int mouseX=0;
    int mouseY=0;
    int handleX=0;//摇杆
    int handleY=0;
    int handleR=0;
    int padX=0;//底盘
    int padY=0;
    int padR=0;
    double handPadDis=0.0;//两圆圆心距离
    bool mousePressed=false;
    QTimer *tim;
    double xs=0.0;
    double ys=0.0;
private:
    QLabel *lab1;
    QLabel *lab2;
    QPushButton *pusleft;
    QPushButton *pusup;
    QPushButton *pusdown;
    QPushButton *pusright;
private slots:
    void leftu();
    void upu();
    void downu();
    void rightu();

    void getKeyNum();

};

#endif // HANDLE_H
