#include "ipcsender.h"

#include <QHostAddress>
#include <QTcpSocket>

ipcsender::ipcsender(QString ip)
{
    succit = new QTcpSocket();
    QHostAddress host (ip);
    succit->connectToHost(host, 20060);
    if(succit->waitForConnected())
           qInfo() << "Connection successful.";
    else{
            qInfo() << succit->errorString();
       }
}

void ipcsender::sendIRRC(QString code)
{
    sendData('C', "IRCC", code.toUtf8());
}

void ipcsender::sendData(char type, QString command, QByteArray data)
{
    if(succit->isOpen())
    {
        QByteArray messageData;

        messageData.append(_header, 2);
        messageData.append(type);
        messageData.append(command);
        messageData.append(data);
        messageData.append(_footer);
        qInfo() << messageData.size();
        succit->write(messageData);
        qInfo() << "sent";
    }
    else
    {
        qInfo() << "Not connected.";
    }

}
