#include "localserver.h"
#include <QTextStream>
#include <QTcpSocket>

LocalServer::LocalServer(QObject *parent)
{
    mSocket = nullptr;
    connect(this, &LocalServer::newConnection, [&]() {
        mSocket = nextPendingConnection();
    });
}

void LocalServer::send(const QString &msj) {
    if(mSocket) {
        QTextStream T(mSocket);
        T << msj;
        mSocket->flush();
    }
}
