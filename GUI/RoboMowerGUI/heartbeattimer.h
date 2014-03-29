#ifndef HEARTBEATTIMER_H
#define HEARTBEATTIMER_H

#include <QTimer>
#include <QDataStream>

class HeartbeatTimer : public QTimer
{
    Q_OBJECT

    //We will count all the time, that passed in miliseconds
    qint16 timePassed;

    signals:
    void getHB(const QByteArray &cmd);
    void HBon();
    void HBoff();

    private:
    bool m_hb;

    public:

    explicit HeartbeatTimer(QObject *parent = 0) : QTimer(parent)
    {
        timePassed = 0;
        m_hb = false;

        connect(this, SIGNAL(timeout()), this, SLOT(sendHeartbeat()));
        connect(this, SIGNAL(timeout()), this, SLOT(rxHeartbeat()));
    }

    void setHB(bool hb)
    {
        m_hb = hb;
    }

    private slots:

    //this slot will be connected with the Timers timeout() signal.
    //after you start the timer, the timeout signal will be fired every time,
    //when the amount interval() time passed.
    void sendHeartbeat()
    {
        timePassed+=interval()/1000; //we increase the time passed
        QByteArray data;
        QDataStream stream(&data, QIODevice::WriteOnly);
        stream.setByteOrder(QDataStream::LittleEndian);

        stream << (unsigned char)0xDE << (unsigned char)0xAD << (unsigned char)0xA1 << timePassed << (unsigned char)0xBE << (unsigned char)0xEF;

        emit getHB(data);
        //this->start();
        //qDebug()<<timePassed; //and debug our collected time
    }

    void rxHeartbeat()
    {
        if(m_hb == true)
        {
            emit HBon();
            m_hb = false;
        }
        else
            emit HBoff();
    }
};

#endif // HEARTBEATTIMER_H
