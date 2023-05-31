//#include "mainwindow.h"

//#include <QApplication>

//int main(int argc, char *argv[])
//{
// //    QApplication a(argc, argv);
// //    MainWindow w;
// //    w.show();
// //    return a.exec();

//}

#include <QCoreApplication>
 #include <QtSql>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("testqtconn");
    db.setUserName("root");
    db.setPassword("123456");
 // db.open();
    if (db.open())
    {
        qDebug() << "Database connected!";
        QSqlQuery query;
        query.prepare("SELECT * FROM login");
        if (query.exec())
        {
            while (query.next())
            {
                QString name = query.value(0).toString();
                int age = query.value(1).toInt();
                qDebug() << "Name: " << name << "Age: " << age;
            }
        }
        else
        {
            qDebug() << "Query failed: " << query.lastError().text();
        }
    }
    else
    {
        qDebug() << "Database failed to connect: " << db.lastError().text();
    }

    return a.exec();
}
