#ifndef MYSQL_H
#define MYSQL_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantList>
QT_BEGIN_NAMESPACE
namespace Ui { class Mysql; }
QT_END_NAMESPACE

class Mysql : public QMainWindow
{
    Q_OBJECT

public:
    Mysql(QWidget *parent = nullptr);
    ~Mysql();

private:
    Ui::Mysql *ui;
};
#endif // MYSQL_H
