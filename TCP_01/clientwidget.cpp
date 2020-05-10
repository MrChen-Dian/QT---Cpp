#include "clientwidget.h"
#include "ui_clientwidget.h"

Clientwidget::Clientwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Clientwidget)
{
    ui->setupUi(this);
    tcpsocket = NULL;

    tcpsocket = new QTcpSocket(this);

    connect(tcpsocket, &QTcpSocket::connected,
            [=]()
                {
                ui->textBread->setText("成功与服务器建立连接！~");
                }
            );
    connect(tcpsocket, &QTcpSocket::readyRead,
            [=]()
            {  //读取数据
                QByteArray array =tcpsocket->readAll();
                //输出数据
                ui->textBread->append(array);
            }
            );
}

Clientwidget::~Clientwidget()
{
    delete ui;
}

void Clientwidget::on_connextButton_clicked()
{
    //获取服务器得ip和端口
    QString ip = ui->lineip->text();
    qint16 port = ui->lineport->text().toUInt();

    //主动和服务器建立连接
    tcpsocket->connectToHost(QHostAddress(ip),port);
}

void Clientwidget::on_sendButton_clicked()
{
    //获取编辑框内容
    QString str = ui->textBwrite->toPlainText();
    //发送数据
    tcpsocket->write(str.toUtf8().data());


}

void Clientwidget::on_closeButton_clicked()
{
    //主动断开连接
    tcpsocket->disconnectFromHost();
    tcpsocket->close();
}
