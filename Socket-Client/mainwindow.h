#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE

namespace Ui {
    class MainWindow;
}

class QTcpSocket;

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_connectBtn_clicked();

    void on_quitBtn_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *mSocket;
};
#endif // MAINWINDOW_H
