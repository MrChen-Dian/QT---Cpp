#include "mysql.h"
#include "ui_mysql.h"

Mysql::Mysql(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Mysql)
{
    ui->setupUi(this);
    //打印QT支持的数据库
    qDebug() << QSqlDatabase::drivers();
    /***创建一个数据库***/
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");//添加数据库

    db.setHostName("localhost");//使用的数据库、IP
    db.setUserName("root");    //使用的数据库名
    db.setPassword("1234567Ed");//使用的数据库密码
    db.setDatabaseName("info"); //使用的数据库
    if(db.open())
    {
        QMessageBox::warning(this, "错误", db.lastError().text());
        return;
    }
    QSqlQuery query; //创建数据库、插入
    query.exec("");  //SQl语句
    query.prepare("");//预插入 values(?,?,?) //oracle风格 values(:name, :age, :score) query.bindValue().
    /****给字段设置内容****/
    QVariantList namelist;
    namelist << "xiaoming" <<"xiaolong" << "xiaojiang";

    QVariantList ageList;
    ageList << 11 << 22 << 23;

    QVariantList scorelist;
    scorelist << 59 << 69 << 79;

    query.addBindValue(namelist);
    query.addBindValue(ageList);
    query.addBindValue(scorelist);

    query.execBatch();
    /******按顺序绑定*********/

    /***创建多个个数据库***/
    /*
    QSqlDatabase db1 = QSqlDatabase::addDatabase("QMYSQL","SQL1");//添加数据库

    db1.setHostName("localhost");//使用的数据库、IP
    db1.setUserName("root");    //使用的数据库名
    db1.setPassword("1234567Ed");//使用的数据库密码
    db1.setDatabaseName("info"); //使用的数据库
    if(db1.open())
    {
        QMessageBox::warning(this, "错误", db.lastError().text());
        return;
    }
    QSqlQuery query1; //创建数据库
    query1.exec("");  //SQl语句
    */
    /***创建多个个数据库***/

}

Mysql::~Mysql()
{
    delete ui;
}

