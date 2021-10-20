#ifndef MODBUS_H
#define MODBUS_H

#include <QModbusClient>
#include <QModbusDataUnit>
#include <QSerialPort>
#include <QModbusRtuSerialMaster>
#include <QModbusTcpClient>
#include <QObject>
#include <QTimer>
#include <QObject>

class  microanalyzer;

class modbus : public QObject
{
    Q_OBJECT
public:
    explicit modbus(QObject *parent = nullptr);

    bool initModbusSerialMaster(QString portName, qint32 baudRate, QSerialPort::DataBits dataBits,
                         QSerialPort::Parity parity, QSerialPort::StopBits stopBits);

    bool connectDevice();

    void readRegisterData(quint16 startAddress,quint16 num, quint16 slaveAddress);

signals:

    void error_signal(QString errorString);

    void stateChanged_signal(int state);

    void readData_signal(int address,int value);

public slots:

   void readyRead();

private:

   QModbusClient* m_master;

};

#endif // MODBUS_H
