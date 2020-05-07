#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include <QTcpServer>//监听
#include <QTcpSocket>//通信

QT_BEGIN_NAMESPACE
namespace Ui { class ServerWidget; }
QT_END_NAMESPACE


class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    ServerWidget(QWidget *parent = nullptr);
    ~ServerWidget();

private slots:
    void on_sendButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::ServerWidget *ui;

    QTcpServer* tcpserver;
    QTcpSocket* tcpsocket;

};
#endif // SERVERWIDGET_H
