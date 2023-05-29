#include "mysqllite.h"
#include<QSqlDatabase>
#include<sqltypes.h>
#include<sqlext.h>
#include<QSqlError>
mysqllite::mysqllite()
{

}

mysqllite::~mysqllite()
{

}

/**
 * @brief connectToMysql 连接到
 * @param host 服务器地址
 * @param port 数据库监听端口
 * @param dbName 数据库名称
 * @param userName 用户名
 * @param password 密码
 * @return 成功返回true
 */
bool mysqllite::connectToMysql(const QString &host, int port, const QString &dbName, const QString &userName, const QString &password)
{
    //QUuid qUuid = QUuid::createUuid();
    //QString strUuid = qUuid.toString();
    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setHostName(host);
    m_db.setPort(port);
    m_db.setDatabaseName(dbName);
    m_db.setUserName(userName);
    m_db.setPassword(password);
    m_db.setConnectOptions("MYSQL_OPT_RECONNECT=1"); // 支持断线重连
    if (!m_db.open()) {
        m_db.setConnectOptions();  //清空连接字符串
        m_lastError = m_db.lastError().text();
        qDebug() << "DB open last error:" << m_lastError.toStdString().c_str();
        return false;
    }
    return true;
}

/**
 * @brief insertRecord 插入一条数据
 * @param table 表名
 * @param record 表数据
 * @return 成功返回true
 */
bool mysqllite::insertRecord(const QString &table, const MStr &record)
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

/**
 * @brief deleteRecord 删除表中数据
 * @param table 表名
 * @param filter 筛选条件
 * @return 成功返回true
 */
bool mysqllite::deleteRecord(const QString &table, const MStr &filter)
{
    QString strSql = QString("DELETE FROM %1 %2")
                         .arg(table).arg(getCondition(filter));
    return executeSql(strSql);
}
/**
 * @brief readRecord 获取数据库数据
 * @param table 表名
 * @param fields 查询字段表达式
 * @param filter 筛选条件
 * @param records 查询结果
 * @return 成功返回true
 */
bool mysqllite::readRecords(const QString &table, const QString &fields, const MStr &filter, VMStr &records)
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
/**
 * @brief updateRecord 更新表中数据
 * @param table 表名
 * @param filter 筛选条件
 * @param data 修改的字段和值
 * @return 成功返回true
 */
bool mysqllite::updateRecord(const QString &table, const MStr &filter, MStr &data)
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
/**
 * @brief executeSql 执行sql语句
 * @param strSql sql语句
 * @return 成功返回true
 */
bool mysqllite::executeSql(const QString &strSql)
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
/**
 * @brief getCondition 组装where子句
 * @param filter 筛选条件
 * @return 返回组装结果
 */
QString mysqllite::getCondition(const MStr &filter)
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
/**
 * @brief getVariantString 获取未知类型的变量为字符串
 *  如果是字符串则返回用单引号包裹的字符串，整型和浮点数等非字符类型，直接转成字符串
 * @param var 输入变量
 * @return 返回字符串
 */
QString mysqllite::getVariantString(const QVariant &var)
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
bool mysqllite::closeSql()
{
    m_db.close();
    return true;
}
