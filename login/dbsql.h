#ifndef DBSQL_H
#define DBSQL_H

#include <QWidget>
#include<login.h>
#include<QSqlDatabase>
#include <QDir>
#include <QDate>
#include <QDateTime>
#include <QFileInfo>
#include <QString>
#include <QTime>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QVariant>
#include<QSqlError>
class dbsql : public QWidget
{
    Q_OBJECT
public:
    dbsql();
    ~dbsql();
    typedef QMap<QString, QVariant> MStr;// 存放查询条件和单条数据
    typedef QVector<MStr> VMStr;// 保存查询结果
public:
    bool connectToMysql(const QString &host, int port, const QString &dbName, const QString &userName, const QString &password);
    void creattable(QString str);//创建表
    bool readtable(QString str);
    void deletable(QString str);
    bool insertRecord(QString table,QString str1,QString str2,QString str3);
    bool insertRecord(const QString &table, const MStr &record);

    bool deleteRecord(const QString &table, const MStr &filter);
    bool deleteRecord(const QString table, QString data);
    bool readRecords(const QString &table, const QString &fields, const MStr &filter, VMStr &records);
    bool readRecord(QString table,QString str[]);

    bool updateRecord(const QString &table, const MStr &filter, MStr &data);
    bool executeSql(const QString &strSql);
    QString getCondition(const MStr &filter);
    QString getVariantString(const QVariant &var);
    bool closeSql();
public:
    QSqlDatabase m_db;
    QString m_lastError;

};

#endif // DBSQL_H
