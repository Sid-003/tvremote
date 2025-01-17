#ifndef IPCSENDER_H
#define IPCSENDER_H

#include <QString>
#include <QUdpSocket>
#include <qtcpsocket.h>




class ipcsender
{
public:

    ipcsender(QString ip);

    void sendIRRC(QString code);
    void sendData(char type, QString command, QByteArray data);
private:
    const char _header[2] = {0x2A, 0x53};
    const char _footer = 0x0A;
    QTcpSocket* succit;
};

#endif // IPCSENDER_H
