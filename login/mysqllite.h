#ifndef MYSQL_H
#define MYSQL_H

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
//#include<QUuid>

class mysqllite
{
    Q_OBJECT
public:
    mysqllite();
    ~mysqllite();
    typedef QMap<QString, QVariant> MStr;// 存放查询条件和单条数据
    typedef QVector<MStr> VMStr;// 保存查询结果
public:
   bool connectToMysql(const QString &host, int port, const QString &dbName, const QString &userName, const QString &password);
   bool insertRecord(const QString &table, const MStr &record);
   bool deleteRecord(const QString &table, const MStr &filter);
   bool readRecords(const QString &table, const QString &fields, const MStr &filter, VMStr &records);
   bool updateRecord(const QString &table, const MStr &filter, MStr &data);
   bool executeSql(const QString &strSql);
   QString getCondition(const MStr &filter);
   QString getVariantString(const QVariant &var);
   bool closeSql();
   public:
       QSqlDatabase m_db;
       QString m_lastError;
};

#endif // MYSQL_H
