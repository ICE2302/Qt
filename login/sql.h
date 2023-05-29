#ifndef SQL_H
#define SQL_H

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
class sql : public QWidget
{
    Q_OBJECT
public:
//    explicit sql(QWidget *parent = nullptr);

public:
    sql();
    ~sql();
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

#endif // SQL_H
