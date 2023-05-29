#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QLabel>

#include <QMainWindow>
#include<QPushButton>
#include<QLineEdit>
#include<QVBoxLayout>


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


signals:
private:
    void init();
    QLabel * label;
    QLabel*  syslabel;
    QPushButton * loginbtn;
    QLineEdit* username;
    QLineEdit* passwd;
    QVBoxLayout * mainlayout;


private slots:
    void closeit();

};
#endif // MAINWINDOW_H
