#include "microanalyzer.h"
#include <QDebug>

microAnalyzer::microAnalyzer(QObject *parent) : QObject(parent)
{

}

void microAnalyzer::readData()
{

//    QString portName = "/dev/ttySTM2";
//    modbus *m_master=new modbus();
//    m_master->initModbusSerialMaster(portName,QSerialPort::Baud115200,QSerialPort::Data8,QSerialPort::NoParity,QSerialPort::OneStop);
//    m_master->connectDevice();
    m_master->readRegisterData(0,16,1);
//    QObject::connect(m_master,SIGNAL(readData_signal(int,int)),this,SLOT(getData(int,int)));
    m_master->readRegisterData(55,9,1);
//    QObject::connect(m_master,SIGNAL(readData_signal(int,int)),this,SLOT(getData(int,int)));
    m_master->readRegisterData(150,5,1);
    connect(m_master,SIGNAL(readData_signal(int,int)),this,SLOT(getData(int,int)));
}

void microAnalyzer::connectSensor()
{

    QString portName = "/dev/ttySTM2";

    m_master->initModbusSerialMaster(portName,QSerialPort::Baud115200,QSerialPort::Data8,QSerialPort::NoParity,QSerialPort::OneStop);
    m_master->connectDevice();
}



void microAnalyzer::getData(int address, int value)
{

    SensorBoardName.resize(13);
    int aux_1=0;
    int aux_2=0;


    switch (address) {
    case 0:
        gsm.setYear(value);
        break;
    case 1:
        gsm.setNumberWeek(value);
        break;
    case 2:
        gsm.setSerial(value);
        break;
    case 4:
        SensorBoardName[0]=value;
        break;
    case 5:
        SensorBoardName[1]=value;
        break;
    case 6:
        SensorBoardName[2]=value;
        break;
    case 7:
        SensorBoardName[3]=value;
        break;
    case 8:
        SensorBoardName[4]=value;
        break;
    case 9:
        SensorBoardName[5]=value;
        break;
    case 10:
        SensorBoardName[6]=value;
        break;
    case 11:
        SensorBoardName[7]=value;
        break;
    case 12:
        SensorBoardName[8]=value;
        break;
    case 13:
        SensorBoardName[9]=value;
        break;
    case 14:
        aux_1=1;
        SensorBoardName[10]=value;
        break;
    case 55:
        gds.setYear(value);
        break;
    case 56:
        gds.setMonth(value);
        break;
    case 57:
        aux_2=1;
        gds.setDay(value);
        break;
    case 60:
        gscp.setAddress(value);
        break;
    case 61:
        gscp.setBaudRate(value);
        break;
    case 62:
        gscp.setCharLength(value);
        break;
    case 63:
        gscp.setParity(value);
        break;
    case 64:
        gscp.setStopBits(value);
        break;

    case 150:
        map.sensorValues()->setTemperaturemv(value);
        qDebug()<<"Temperature(mV): "<<map.sensorValues()->temperaturemv();
        break;
    case 151:
        gsv.setTemperatureDegrees(value);
        qDebug()<<"Temperature(Degrees): "<<gsv.temperatureDegrees();
        break;
    case 152:
        gsv.setPhasemv(value);
        qDebug()<<"Phase(mV): "<<gsv.phasemv();
        break;
    case 153:
        gsv.setPhaseDegrees(value);
        qDebug()<<"Phase(Degrees): "<<gsv.phaseDegrees();
        break;
    case 154:
        gsv.setattenuationmv(value);
        qDebug()<<"Attenuation(mV): "<<gsv.attenuationmv();
        break;
    case 155:
        gsv.setAttenuationdb(value);
        qDebug()<<"Attenuation(dB): "<<gsv.attenuationdb();
        break;
    }

    if(aux_1)
    {

        SensorBoardName.toHex().toStdString().c_str();
        map.setSensorBoardName(SensorBoardName);
        qDebug()<<map.sensorBoardName();
    }
    if(aux_2)
    {
        SensorSoftDate.setDate(gds.year(),gds.month(),gds.day());
        gds.setDateSoftwareBuild(SensorSoftDate);
        qDebug()<<gds.dateSoftwareBuild();
    }

}
