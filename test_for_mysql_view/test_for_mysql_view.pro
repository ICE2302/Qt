QT       += core gui sql
# QT += mysql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui
#Mysql的动态库和头文件
#INCLUDEPATH += E:/SQL/MYSQL/include
#LIBS += -L E:/SQL/MYSQL/lib -lmysqlclient -lmysqlcppconn
#INCLUDEPATH+= C:/Program Files/MySQL/MySQL Connector C++ 8.0/include
#LIBS+= -L C:/Program Files/MySQL/MySQL Connector C++ 8.0/lib64/vs14/
# 链接 MySQL C++ Connector 的动态链接库文件
#win32:CONFIG(release, debug|release): LIBS += "C:/Program Files/MySQL/MySQL Connector C++ 8.0/lib64/vs14/mysqlcppconn8.lib"
#else:win32:CONFIG(debug, debug|release): LIBS += "C:/Program Files/MySQL/MySQL Connector C++ 8.0/lib64/vs14/mysqlcppconn8.lib"
#else:unix: LIBS += -L"/usr/local/mysql-connector-c++-8.0.26/lib64" -lmysqlcppconn8

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
