#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>

#include <QTcpSocket>
#include <QHostAddress>
namespace Ui {
class Clientwidget;
}

class Clientwidget : public QWidget
{
    Q_OBJECT

public:
    explicit Clientwidget(QWidget *parent = nullptr);
    ~Clientwidget();

private slots:
    void on_connextButton_clicked();

    void on_sendButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::Clientwidget *ui;

    QTcpSocket* tcpsocket;
};

#endif // CLIENTWIDGET_H
