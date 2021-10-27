#ifndef MICROANALYZER_H
#define MICROANALYZER_H

#include <QObject>
#include "modbus.h"
#include "maparametters.h"

class modbus;
class maParametters;
class microAnalyzer;

class microAnalyzer : public QObject
{
    Q_OBJECT
public:
    explicit microAnalyzer(QObject *parent = nullptr);

    Q_INVOKABLE void readData();
    Q_INVOKABLE void connectSensor();

signals:

public slots:

   void getData(int address, int value);

private:

   modbus *m_master=new modbus();
   maParametters map;
   GroupSerialNumber gsm;
   QByteArray SensorBoardName;
   GroupDateSoftware gds;
   QDate SensorSoftDate;
   GroupSensorCommParametters gscp;
   GroupSensorValues gsv;

//   QModbusClient* m_master;


};

#endif // MICROANALYZER_H
