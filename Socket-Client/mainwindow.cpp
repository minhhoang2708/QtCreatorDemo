#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QTcpSocket>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    mSocket = new QTcpSocket(this);
    connect(mSocket, &QTcpSocket::readyRead, [&]() {
       QTextStream T(mSocket);
       ui->listWidget->addItem(T.readAll());
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_connectBtn_clicked()
{
    mSocket->connectToHost(ui->serverText->text(), ui->portText->value());
}

void MainWindow::on_quitBtn_clicked()
{
    close();
}
