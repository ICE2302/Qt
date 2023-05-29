#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
#include<QTimer>
#include<QPushButton>
#include<QVBoxLayout>
#include<QColor>
#include<QRadialGradient>
#include<QLinearGradient>
#include<QPalette>

#include"sonwindow.h"

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
private:
    Ui::MainWindow *ui;
    void init();
    QLabel* mainlabel;

    QPushButton* start;//点击开始，彩虹灯开始转换

    QVBoxLayout * startlayout;//设置开始按钮在下方

    sonwindow* window;//跳转到彩虹灯窗口

    QWidget* cnteralwindow;

public slots:
    void alter();

};
#endif // MAINWINDOW_H
