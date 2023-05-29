#ifndef SONWINDOW_H
#define SONWINDOW_H
#include <QMainWindow>
#include<QLabel>
#include<QTimer>
#include<QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QColor>
#include<QRadialGradient>
#include<QLinearGradient>
#include<QPalette>
#include<QDebug>

class sonwindow : public QWidget
{
    Q_OBJECT
public:
    sonwindow(QWidget * parent=NULL);
    ~sonwindow();

private:

     QTimer* timer;
     //rainbow Layout
     QVBoxLayout* afterlayout;
     //rainbow colorlabel
     QVector<QLabel*>rainbow_color;
//     QLabel * red_label;
//     QLabel * orange_label;
//     QLabel * yellow_label;
//     QLabel * green_label;
//     QLabel * lightblue_label;
//     QLabel * blue_label;
//     QLabel * purple_label;
 signals:




public slots :
     void process();
};

#endif // SONWINDOW_H
