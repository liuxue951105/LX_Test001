#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostAddress>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    status = false;
    port = 8010;
//    msg="ON";
    ui->portText->setText(QString::number(port));
    ui->serverIPLineEdit->setText("192.168.3.28");
    serverIP = new QHostAddress();
//    tcpSocket = new QTcpSocket(this);
    setBtnStatus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotConnected()
{
    ui->enterBtn->setText("断开");
//    int length=0;
//    QString msg="ON";
//    if((length=tcpSocket->write(msg.toLatin1(),msg.length()))!=msg.length())
//    {
//        return;
//    }
}

void MainWindow::slotDisconnected()
{
    ui->enterBtn->setText("链接");
}

void MainWindow::dataReceived()
{
    while (tcpSocket->bytesAvailable()>0) {
        QByteArray datagram;
        datagram.resize(tcpSocket->bytesAvailable());
        tcpSocket->read(datagram.data(),datagram.size());
        QString msg=QString("\n")+datagram.data();
//        ui->Received->setText(ui->Received->toPlainText().append(msg));
    }
}


void MainWindow::on_enterBtn_clicked()
{
    if(!status)
    {
        QString ip = ui->serverIPLineEdit->text();
        if(!serverIP->setAddress(ip))
        {
            QMessageBox::information(this,tr("error"),tr("server ip address error!"));
            return;
        }

        tcpSocket = new QTcpSocket(this);
        connect(tcpSocket,SIGNAL(connected()),this,SLOT(slotConnected()));
        connect(tcpSocket,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
        connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(dataReceived()));
        tcpSocket->connectToHost(*serverIP,port);
        status = true;
    }
    else
    {
//        int length=0;
//        QString msg="Leave Chat Room";
//        if((length=tcpSocket->write(msg.toLatin1(),msg.length()))!=msg.length())
//        {
//            return;
//        }
        tcpSocket->disconnectFromHost();
        status = false;
    }
    setBtnStatus();
}


void MainWindow::on_forward_pressed()
{
    msg="ONB";
    tcpSocket->write(msg.toLatin1(),msg.length());
}


void MainWindow::on_forward_released()
{
    msg="ONZ";
    tcpSocket->write(msg.toLatin1(),msg.length());
}

void MainWindow::setBtnStatus()
{
    ui->forward->setEnabled(status);
    ui->Stop->setEnabled(status);
    ui->forward_Left->setEnabled(status);
    ui->forward_Right->setEnabled(status);
    ui->backward_Left->setEnabled(status);
    ui->backward_Right->setEnabled(status);
    ui->move_Left->setEnabled(status);
    ui->move_Right->setEnabled(status);
    ui->turn_Left->setEnabled(status);
    ui->turn_Right->setEnabled(status);
}

void MainWindow::on_forward_Left_pressed()
{
    msg="ONJ";
    tcpSocket->write(msg.toLatin1(),msg.length());
}

void MainWindow::on_forward_Left_released()
{
    msg="ONZ";
    tcpSocket->write(msg.toLatin1(),msg.length());
}


void MainWindow::on_back_pressed()
{
    msg="ONA";
    tcpSocket->write(msg.toLatin1(),msg.length());
}


void MainWindow::on_back_released()
{
    msg="ONZ";
    tcpSocket->write(msg.toLatin1(),msg.length());
}


void MainWindow::on_backward_Right_pressed()
{
    msg="ONG";
    tcpSocket->write(msg.toLatin1(),msg.length());
}


void MainWindow::on_backward_Right_released()
{
    msg="ONZ";
    tcpSocket->write(msg.toLatin1(),msg.length());
}


void MainWindow::on_backward_Left_pressed()
{
    msg="ONH";
    tcpSocket->write(msg.toLatin1(),msg.length());
}


void MainWindow::on_backward_Left_released()
{
    msg="ONZ";
    tcpSocket->write(msg.toLatin1(),msg.length());
}


void MainWindow::on_forward_Right_pressed()
{
    msg="ONI";
    tcpSocket->write(msg.toLatin1(),msg.length());
}


void MainWindow::on_forward_Right_released()
{
    msg="ONZ";
    tcpSocket->write(msg.toLatin1(),msg.length());
}


void MainWindow::on_move_Left_pressed()
{
    msg="OND";
    tcpSocket->write(msg.toLatin1(),msg.length());
}


void MainWindow::on_move_Left_released()
{
    msg="ONZ";
    tcpSocket->write(msg.toLatin1(),msg.length());
}


void MainWindow::on_move_Right_pressed()
{
    msg="ONC";
    tcpSocket->write(msg.toLatin1(),msg.length());
}


void MainWindow::on_move_Right_released()
{
    msg="ONZ";
    tcpSocket->write(msg.toLatin1(),msg.length());
}


void MainWindow::on_turn_Left_pressed()
{
    msg="ONF";
    tcpSocket->write(msg.toLatin1(),msg.length());
}


void MainWindow::on_turn_Left_released()
{
    msg="ONZ";
    tcpSocket->write(msg.toLatin1(),msg.length());
}


void MainWindow::on_turn_Right_pressed()
{
    msg="ONE";
    tcpSocket->write(msg.toLatin1(),msg.length());
}


void MainWindow::on_turn_Right_released()
{
    msg="ONZ";
    tcpSocket->write(msg.toLatin1(),msg.length());
}

