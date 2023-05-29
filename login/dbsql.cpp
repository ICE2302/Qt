#include "dbsql.h"


dbsql::dbsql()
{

}

dbsql::~dbsql()
{

}

bool dbsql::connectToMysql(const QString &host, int port, const QString &dbName, const QString &userName, const QString &password)
{


    m_db = QSqlDatabase::addDatabase("QPSQL");
    m_db.setHostName(host);
    m_db.setPort(port);
    m_db.setDatabaseName(dbName);
    m_db.setUserName(userName);
    m_db.setPassword(password);
   // m_db.setConnectOptions("QPSQL_OPT_RECONNECT=1"); // 支持断线重连
    if (!m_db.open()) {
        m_db.setConnectOptions();  //清空连接字符串
        m_lastError = m_db.lastError().text();
        qDebug() << "DB INSERT INTO last error:" << m_lastError.toStdString().c_str();
        return false;
    }
    return true;
}

void dbsql::creattable(QString str)
{
    QSqlQuery query;
    QString str1=QString("CREATE TABLE %1(users varchar,passy varchar,flat varchar,PRIMARY KEY(users));").arg(str);
    qDebug()<<str1;
    query.exec(str1);
}

bool dbsql::readtable(QString str)
{
    QSqlQuery query;
    str= QString("select count(*) from pg_class where relname = '%1';").arg(str);
    return query.exec(str);
}

void dbsql::deletable(QString str)
{
    QSqlQuery query;
    str= QString("DROP TABLE %1;").arg(str);
    query.exec(str);
}

bool dbsql::insertRecord(QString table,QString str1,QString str2,QString str3)
{
    QString sql = QString("INSERT INTO %1 (users,passy,flat) VALUES('%2','%3','%4');").arg(table).arg(str1).arg(str2).arg(str3);
    QSqlQuery query;
    if(query.exec(sql))
    {
        return true;
    }
    else
    {
        qDebug()<<"aaaaaa";
    }
    return true;
}
bool dbsql::insertRecord(const QString &table, const dbsql::MStr &record)
{
    QString fields = record.keys().join(",");
    QVariantList valueList = record.values();
    QStringList temp;
    for (int i = 0; i < valueList.size(); i++)
    {
        temp.append(getVariantString(valueList[i]));
    }
    QString values = temp.join(",");
    QString strSql = QString("INSERT INTO %1 (%2) VALUES(%3)")
                         .arg(table).arg(fields).arg(values);
    return executeSql(strSql);
}

bool dbsql::deleteRecord(const QString &table, const dbsql::MStr &filter)
{
    QString strSql = QString("DELETE FROM %1 %2").arg(table).arg(getCondition(filter));
    return executeSql(strSql);
}

bool dbsql::deleteRecord(const QString table, QString data)
{
    QString strSql = QString("delete from %1 where users ='%2';").arg(table).arg(data);
    return executeSql(strSql);
}

bool dbsql::readRecords(const QString &table, const QString &fields, const dbsql::MStr &filter, dbsql::VMStr &records)
{
    QString condition = getCondition(filter);
    QString strSql = QString("SELECT %1 FROM `%2` %3").arg(fields).arg(table).arg(condition);
    qDebug() << strSql;
    if (m_db.isOpen())
    {
        QSqlQuery sqlQuery(m_db);
        if (sqlQuery.exec(strSql))
        {
            while (sqlQuery.next())
            {
                MStr record;
                // 遍历一条记录的每一个字段
                for (int i = 0; i < sqlQuery.record().count(); i++)
                {
                    QString fieldName = sqlQuery.record().fieldName(i);
                    QVariant value = sqlQuery.record().value(i);
                    record[fieldName] = value;
                }
                records.append(record);
            }
            return true;
        }
        m_lastError = sqlQuery.lastError().text();
    }
    return false;
}

bool dbsql::readRecord(QString table,QString str[])
{
    QString strl=QString("select * from %1;").arg(table);
    int i=0;
    if (m_db.isOpen())
    {

        QSqlQuery sqlQuery(m_db);

        if (sqlQuery.exec(strl))
        {

            while(sqlQuery.next())
            {
                str[i]=sqlQuery.value(0).toString();
                str[i+1]=sqlQuery.value(1).toString();
                str[i+2]=sqlQuery.value(2).toString();
                i=i+3;
                qDebug()<<str;
            }
            return  true;
        }
        else

        {
            return  false;

        }
    }

}

bool dbsql::updateRecord(const QString &table, const dbsql::MStr &filter, dbsql::MStr &data)
{
    bool ret = false;
    QStringList fragments;
    for (MStr::const_iterator iter = data.begin(); iter != data.end(); iter++)
    {
        QString fragment = QString("`%1` = %2")
                               .arg(iter.key())
                               .arg(getVariantString(iter.value()));
        fragments.append(fragment);
    }
    if (fragments.size() > 0)
    {
        QString setExp = fragments.join(",");
        QString strSql = QString("UPDATE %1 SET %2 %3")
                             .arg(table).arg(setExp).arg(getCondition(filter));
        ret = executeSql(strSql);
    }

    return ret;
}

bool dbsql::executeSql(const QString &strSql)
{
    qDebug() << "Execute SQL statement:" << strSql.toStdString().c_str();
    if (m_db.isOpen()) {
        QSqlQuery sqlQuery(m_db);
        if (sqlQuery.exec(strSql)) {
            return true;
        }
        else
        {
            m_lastError = sqlQuery.lastError().text();
            int sqlQueryLastErrorNumber = sqlQuery.lastError().number();
            qDebug() << "Sql query last error code:"
                     << sqlQueryLastErrorNumber << ",text:"
                     << m_lastError.toStdString().c_str();
        }
    }
    return false;
}

QString dbsql::getCondition(const dbsql::MStr &filter)
{
    QString condition = "";
    QStringList fragments;
    for (MStr::const_iterator iter = filter.begin(); iter != filter.end(); iter++)
    {
        QString fragment = QString("`%1` = %2")
                               .arg(iter.key())
                               .arg(getVariantString(iter.value()));
        fragments.append(fragment);
    }
    if (fragments.size() > 0)
    {
        condition = "WHERE " + fragments.join(" AND ");
    }
    return condition;
}

QString dbsql::getVariantString(const QVariant &var)
{
    if (var.type() == QVariant::String)
    {
        return QString("\'%1\'").arg(var.toString());
    }
    else
    {
        return var.toString();
    }
}

bool dbsql::closeSql()
{
    m_db.close();
    return true;
}
