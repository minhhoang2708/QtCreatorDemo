#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "localserver.h"
#include <QTcpServer>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mLocalServer = new LocalServer(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_sendBtn_clicked()
{
      mLocalServer->send(ui->lineEdit->text());
}

void MainWindow::on_StartBtn_clicked()
{
    if(!mLocalServer->listen(QHostAddress::Any, ui->portBox->value())) {
         QMessageBox::critical(this, "Erro", mLocalServer->errorString());
    } else {
         QMessageBox::information(this, "Server", "Initial...");
    }
}

void MainWindow::on_PutOffBtn_clicked()
{
    close();
}
