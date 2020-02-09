#include "widget.h"
#include <QApplication>
#include "signer.h"
#include <QSqlDatabase>
#include <qDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("mr");
    db.setUserName("root");
    db.setPassword("123456");
    if(db.open())
    {
        qDebug()<<"打开数据库成功！";
    }
    else
    {
        qDebug()<<"打开数据库失败！";
    }
    signer w;
    w.show();

    return a.exec();
}
