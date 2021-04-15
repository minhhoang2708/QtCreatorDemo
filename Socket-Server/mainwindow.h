#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class LocalServer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_sendBtn_clicked();

    void on_StartBtn_clicked();

    void on_PutOffBtn_clicked();

private:
    Ui::MainWindow *ui;
    LocalServer *mLocalServer;
};
#endif // MAINWINDOW_H
