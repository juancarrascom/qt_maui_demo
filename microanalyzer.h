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

    void readData();

signals:

public slots:

   void getData(int address, int value);

private:

   modbus* m_device;
   QModbusClient* m_master;


};

#endif // MICROANALYZER_H
