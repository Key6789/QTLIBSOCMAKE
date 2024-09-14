#include "QTWidgetAndLib.h"
#include "./ui_QTWidgetAndLib.h"
#include <QVBoxLayout>
#include <QLabel>
#include "TcpCommunication.h"


#define __QString(str) QString::fromLocal8Bit(str)
QTWidgetAndLib::QTWidgetAndLib(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QTWidgetAndLib)
{
    ui->setupUi(this);
    /*CommunicationModule::TcpCommunication* tcpComm = new CommunicationModule::TcpCommunication("127.0.0.1",8080,this);
    QWidget * widget = new QWidget(this);
    QVBoxLayout * layout = new QVBoxLayout(widget);
    layout->addWidget(tcpComm->showConnectStatus(widget));
    layout->addWidget(tcpComm->showSendData(widget));
    layout->addWidget(tcpComm->showReceiveData(widget));
    layout->addWidget(tcpComm->showError(widget));
    layout->addWidget(new QLabel("标签"));

    setCentralWidget(widget);*/
   CommunicationModule::TcpCommunication* tcpComm = new CommunicationModule::TcpCommunication("127.0.0.1",8080,this);
   QWidget* widget = new QWidget(this);
   QVBoxLayout* layout = new QVBoxLayout(widget);
   layout->addWidget(tcpComm->showConnectStatus(widget));
   layout->addWidget(tcpComm->showSendData(widget));
   layout->addWidget(tcpComm->showReceiveData(widget));
   layout->addWidget(tcpComm->showError(widget));
   layout->addWidget(new QLabel(__QString("标签")));
   setCentralWidget(widget);
}

QTWidgetAndLib::~QTWidgetAndLib()
{
    delete ui;
}
