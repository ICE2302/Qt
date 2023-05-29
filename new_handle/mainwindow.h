#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include<QMouseEvent>
#include<QPushButton>
#include<QDebug>
#include"handle_label.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:

public slots:

private:
    QLabel * bglabel;
    handlelabel* handle;
    //QMouseEvent *event;





    void init();
//    void mouseMoveEvent(QMouseEvent *event);
//    void mousePressEvent(QMouseEvent *event);
//    void mouseReleaseEvent(QMouseEvent* event);






    //Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
