#pragma execution_character_set("utf-8")
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QHostAddress>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void slotConnected();
    void slotDisconnected();
    void dataReceived();

    void on_enterBtn_clicked();
    void on_forward_pressed();

    void on_forward_released();
    void setBtnStatus();
    void on_forward_Left_pressed();

    void on_forward_Left_released();

    void on_back_pressed();

    void on_back_released();

    void on_backward_Right_pressed();

    void on_backward_Right_released();

    void on_backward_Left_pressed();

    void on_backward_Left_released();

    void on_forward_Right_pressed();

    void on_forward_Right_released();

    void on_move_Left_pressed();

    void on_move_Left_released();

    void on_move_Right_pressed();

    void on_move_Right_released();

    void on_turn_Left_pressed();

    void on_turn_Left_released();

    void on_turn_Right_pressed();

    void on_turn_Right_released();

private:
    Ui::MainWindow *ui;
    quint16 status;
    short port;
    QString msg;
    QTcpSocket* tcpSocket;
    QHostAddress *serverIP;
};
#endif // MAINWINDOW_H
