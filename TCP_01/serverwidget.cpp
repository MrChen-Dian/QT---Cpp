#include "serverwidget.h"
#include "ui_serverwidget.h"

ServerWidget::ServerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerWidget)
{
    ui->setupUi(this);
    //监听套接字，指定父对象，让其自动回收空间
    tcpserver = new QTcpServer(this);

    tcpserver -> listen(QHostAddress::Any,8888);

    setWindowTitle("服务器：8888");

    connect(tcpserver, &QTcpServer::newConnection,
            [=]()
            {
             //取出建立好的连接套接字
             tcpsocket = tcpserver->nextPendingConnection();

             //获取对方的IP和端口
             QString ip = tcpsocket->peerAddress().toString();
             qint16 port =tcpsocket ->peerPort();
             QString temp = QString("[%1:%2]:连接成功").arg(ip).arg(port);

             //在textread上面显示
             ui->textread->setText(temp);

             connect(tcpsocket, &QTcpSocket::readyRead,
                     [=]()
                     {
                         //从通信套接字中取出内容
                         QByteArray array = tcpsocket->readAll();
                         //在textread中显示
                         ui->textread->append(array);
                     }
                     );
            }
            );

}

ServerWidget::~ServerWidget()
{
    delete ui;
}


void ServerWidget::on_sendButton_clicked()
{
    //获取编辑区的内容
    QString str = ui->textwrite->toPlainText();
    //给对方发送数据，使用套接字是tcpsocket（）
    tcpsocket->write( str.toUtf8().data() );
}

void ServerWidget::on_closeButton_clicked()
{
    //断开连接
    tcpsocket->disconnectFromHost();
    tcpsocket->close();
}
