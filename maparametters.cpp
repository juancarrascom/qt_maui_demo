#include "maparametters.h"

maParametters::maParametters(QObject *parent) : QObject(parent)
{

}

GroupSerialNumber *maParametters::serialNumber() const
{
    return m_serialNumber;
}

void maParametters::setSerialNumber(GroupSerialNumber *newSerialNumber)
{
    if (m_serialNumber == newSerialNumber)
        return;
    m_serialNumber = newSerialNumber;
    emit serialNumberChanged();
}

int GroupSerialNumber::year() const
{
    return m_year;
}

void GroupSerialNumber::setYear(int newYear)
{
    if (m_year == newYear)
        return;
    m_year = newYear;
    emit yearChanged();
}

int GroupSerialNumber::numberWeek() const
{
    return m_numberWeek;
}

void GroupSerialNumber::setNumberWeek(int newNumberWeek)
{
    if (m_numberWeek == newNumberWeek)
        return;
    m_numberWeek = newNumberWeek;
    emit numberWeekChanged();
}

int GroupSerialNumber::serial() const
{
    return m_serial;
}

void GroupSerialNumber::setSerial(int newSerial)
{
    if (m_serial == newSerial)
        return;
    m_serial = newSerial;
    emit serialChanged();
}

const QString &maParametters::sensorBoardName() const
{
    return m_sensorBoardName;
}

void maParametters::setSensorBoardName(const QString &newSensorBoardName)
{
    if (m_sensorBoardName == newSensorBoardName)
        return;
    m_sensorBoardName = newSensorBoardName;
    emit sensorBoardNameChanged();
}

int GroupDateSoftware::day() const
{
    return m_day;
}

void GroupDateSoftware::setDay(int newDay)
{
    if (m_day == newDay)
        return;
    m_day = newDay;
    emit dayChanged();
}

int GroupDateSoftware::month() const
{
    return m_month;
}

void GroupDateSoftware::setMonth(int newMonth)
{
    if (m_month == newMonth)
        return;
    m_month = newMonth;
    emit monthChanged();
}

int GroupDateSoftware::year() const
{
    return m_year;
}

void GroupDateSoftware::setYear(int newYear)
{
    if (m_year == newYear)
        return;
    m_year = newYear;
    emit yearChanged();
}

const QDate &GroupDateSoftware::dateSoftwareBuild() const
{
    return m_dateSoftwareBuild;
}

void GroupDateSoftware::setDateSoftwareBuild(const QDate &newDateSoftwareBuild)
{
    if (m_dateSoftwareBuild == newDateSoftwareBuild)
        return;
    m_dateSoftwareBuild = newDateSoftwareBuild;
    emit dateSoftwareBuildChanged();
}

GroupDateSoftware *maParametters::dateSoftware() const
{
    return m_dateSoftware;
}

void maParametters::setDateSoftware(GroupDateSoftware *newDateSoftware)
{
    if (m_dateSoftware == newDateSoftware)
        return;
    m_dateSoftware = newDateSoftware;
    emit dateSoftwareChanged();
}

int GroupSensorCommParametters::address() const
{
    return m_address;
}

void GroupSensorCommParametters::setAddress(int newAddress)
{
    if (m_address == newAddress)
        return;
    m_address = newAddress;
    emit addressChanged();
}

int GroupSensorCommParametters::baudRate() const
{
    return m_baudRate;
}

void GroupSensorCommParametters::setBaudRate(int newBaudRate)
{
    if (m_baudRate == newBaudRate)
        return;
    m_baudRate = newBaudRate;
    emit baudRateChanged();
}

int GroupSensorCommParametters::charLength() const
{
    return m_charLength;
}

void GroupSensorCommParametters::setCharLength(int newCharLength)
{
    if (m_charLength == newCharLength)
        return;
    m_charLength = newCharLength;
    emit charLengthChanged();
}

int GroupSensorCommParametters::parity() const
{
    return m_parity;
}

void GroupSensorCommParametters::setParity(int newParity)
{
    if (m_parity == newParity)
        return;
    m_parity = newParity;
    emit parityChanged();
}

int GroupSensorCommParametters::stopBits() const
{
    return m_stopBits;
}

void GroupSensorCommParametters::setStopBits(int newStopBits)
{
    if (m_stopBits == newStopBits)
        return;
    m_stopBits = newStopBits;
    emit stopBitsChanged();
}

const QString &GroupSensorCommParametters::password() const
{
    return m_password;
}

void GroupSensorCommParametters::setPassword(const QString &newPassword)
{
    if (m_password == newPassword)
        return;
    m_password = newPassword;
    emit passwordChanged();
}

GroupSensorCommParametters *maParametters::sensorCommParametters() const
{
    return m_sensorCommParametters;
}

void maParametters::setSensorCommParametters(GroupSensorCommParametters *newSensorCommParametters)
{
    if (m_sensorCommParametters == newSensorCommParametters)
        return;
    m_sensorCommParametters = newSensorCommParametters;
    emit sensorCommParamettersChanged();
}

GroupSensorValues *maParametters::sensorValues() const
{
    return m_sensorValues;
}

void maParametters::setsensorValues(GroupSensorValues *newSensorValues)
{
    if (m_sensorValues == newSensorValues)
        return;
    m_sensorValues = newSensorValues;
    emit sensorValuesChanged();
}

int GroupSensorValues::temperaturemv() const
{
    return m_temperaturemv;
}

void GroupSensorValues::setTemperaturemv(int newTemperaturemv)
{
    if (m_temperaturemv == newTemperaturemv)
        return;
    m_temperaturemv = newTemperaturemv;
    emit temperaturemvChanged();
}

int GroupSensorValues::temperatureDegrees() const
{
    return m_temperatureDegrees;
}

void GroupSensorValues::setTemperatureDegrees(int newTemperatureDegrees)
{
    if (m_temperatureDegrees == newTemperatureDegrees)
        return;
    m_temperatureDegrees = newTemperatureDegrees;
    emit temperatureDegreesChanged();
}

int GroupSensorValues::phasemv() const
{
    return m_phasemv;
}

void GroupSensorValues::setPhasemv(int newPhasemv)
{
    if (m_phasemv == newPhasemv)
        return;
    m_phasemv = newPhasemv;
    emit phasemvChanged();
}

int GroupSensorValues::phaseDegrees() const
{
    return m_phaseDegrees;
}

void GroupSensorValues::setPhaseDegrees(int newPhaseDegrees)
{
    if (m_phaseDegrees == newPhaseDegrees)
        return;
    m_phaseDegrees = newPhaseDegrees;
    emit phaseDegreesChanged();
}

int GroupSensorValues::attenuationmv() const
{
    return m_attenuationmv;
}

void GroupSensorValues::setattenuationmv(int newAttenuationmv)
{
    if (m_attenuationmv == newAttenuationmv)
        return;
    m_attenuationmv = newAttenuationmv;
    emit attenuationmvChanged();
}

int GroupSensorValues::attenuationdb() const
{
    return m_attenuationdb;
}

void GroupSensorValues::setAttenuationdb(int newAttenuationdb)
{
    if (m_attenuationdb == newAttenuationdb)
        return;
    m_attenuationdb = newAttenuationdb;
    emit attenuationdbChanged();
}
