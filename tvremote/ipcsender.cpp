#include "ipcsender.h"

#include <QHostAddress>
#include <QTcpSocket>

ipcsender::ipcsender(QString ip)
{
    succit = new QTcpSocket();
    QHostAddress host (ip);
    succit->connectToHost(host, 20060);
    if(succit->waitForConnected())
           qInfo() << "connected all is good";
    else{
            qInfo() << succit->errorString();
       }
}

void ipcsender::sendIRRC(char *data)
{
    char *command = const_cast<char*>(QString("IRCC").toStdString().c_str());
    char type = 'C';
    char *tp = &type;
    sendData(tp,  command, data);
}

void ipcsender::sendData(char *type, char *command, char *data)
{
    if(succit->isOpen())
    {
        QByteArray messageData;

        messageData.append(_header, 2);
        messageData.append(type, 1);
        messageData.append(command, 4);
        for(int i = 0; i < 16; i++)
        {
            messageData.append(data[i]);
        }
        //footer
        messageData.append(0x0A);
        qInfo() << messageData.size();
        succit->write(messageData);
        qInfo() << "sent";
    }
    else
    {
        qInfo() << "fucking thing isn't connected.";
    }

}
