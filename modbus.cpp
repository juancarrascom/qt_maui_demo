#include "modbus.h"
#include <QDebug>

modbus::modbus(QObject *parent) : QObject(parent)
{

}

bool modbus::initModbusSerialMaster(QString portName, qint32 baudRate, QSerialPort::DataBits dataBits, QSerialPort::Parity parity, QSerialPort::StopBits stopBits)
{
    m_master = new QModbusRtuSerialMaster(this);


    if(!m_master)
    {
        qDebug()<<"init master error";
        return 0;
    }

    m_master->setConnectionParameter(QModbusDevice::SerialPortNameParameter,
                                    portName);
    m_master->setConnectionParameter(QModbusDevice::SerialBaudRateParameter,
                                    baudRate);
    m_master->setConnectionParameter(QModbusDevice::SerialDataBitsParameter,
                                    dataBits);
    m_master->setConnectionParameter(QModbusDevice::SerialParityParameter,
                                    parity);
    m_master->setConnectionParameter(QModbusDevice::SerialStopBitsParameter,
                                    stopBits);

    return 1;

}

bool modbus::connectDevice()
{
    if(m_master->connectDevice())
    {
        qDebug()<<"Succesful Connection :)";
        return 1;
    }
    else {
        qDebug()<<"Unsuccessful Connection :(";
        return 0;
    }
}

void modbus::readRegisterData(quint16 startAddress, quint16 num, quint16 slaveAddress)
{
    if(!m_master)
        return;

    QModbusDataUnit readUnit(QModbusDataUnit::HoldingRegisters,startAddress,num);

    if(auto *reply = m_master->sendReadRequest(readUnit,slaveAddress))
    {

        if(!reply->isFinished())
        {
            connect(reply,&QModbusReply::finished,this,&modbus::readyRead);
        }
        else
            delete reply;

    }
    else
    {
        qDebug()<<"Read error: "<<m_master->errorString();
    }

}

void modbus::readyRead()
{


    auto reply = qobject_cast<QModbusReply*>(sender());

    if(!reply)
        return;
    if(reply->error() == QModbusDevice::NoError)
    {

        const QModbusDataUnit unit = reply->result();

        for(uint i = 0; i< unit.valueCount();i++)
        {
            const QString entry = tr("Address:%1,Value:%2").arg(unit.startAddress()+i)
                    .arg(QString::number(unit.value(i),unit.registerType()
                                         <= QModbusDataUnit::Coils?10:16));

//            qDebug()<<entry;

            emit readData_signal(unit.startAddress()+i,unit.value(i));
        }
    }
    else if(reply->error() == QModbusDevice::ProtocolError)
    {
        qDebug()<<"error protocolError"<<reply->errorString();
    }
    else
    {
        qDebug()<<"error:"<<reply->errorString();
    }

    reply->deleteLater();
}
