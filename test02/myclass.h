#ifndef MYCLASS_H
#define MYCLASS_H

#include <QMainWindow>

class myclass : public QMainWindow
{
    Q_OBJECT
public:
    explicit myclass(QWidget *parent = nullptr);

signals:

};

#endif // MYCLASS_H
