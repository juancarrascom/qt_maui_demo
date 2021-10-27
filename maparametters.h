#ifndef MAPARAMETTERS_H
#define MAPARAMETTERS_H

#include <QObject>
#include <QDate>

class GroupSerialNumber : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int year READ year WRITE setYear NOTIFY yearChanged)
    Q_PROPERTY(int numberWeek READ numberWeek WRITE setNumberWeek NOTIFY numberWeekChanged)
    Q_PROPERTY(int serial READ serial WRITE setSerial NOTIFY serialChanged)

public:

    int year() const;
    void setYear(int newYear);

    int numberWeek() const;
    void setNumberWeek(int newNumberWeek);

    int serial() const;
    void setSerial(int newSerial);

signals:
    void yearChanged();

    void numberWeekChanged();

    void serialChanged();

private:

    int m_year;
    int m_numberWeek;
    int m_serial;
};

class GroupDateSoftware: public QObject
{
    Q_OBJECT
    Q_PROPERTY(int day READ day WRITE setDay NOTIFY dayChanged)
    Q_PROPERTY(int month READ month WRITE setMonth NOTIFY monthChanged)
    Q_PROPERTY(int year READ year WRITE setYear NOTIFY yearChanged)
    Q_PROPERTY(QDate dateSoftwareBuild READ dateSoftwareBuild WRITE setDateSoftwareBuild NOTIFY dateSoftwareBuildChanged)

public:

    int day() const;
    void setDay(int newDay);

    int month() const;
    void setMonth(int newMonth);

    int year() const;
    void setYear(int newYear);

    const QDate &dateSoftwareBuild() const;
    void setDateSoftwareBuild(const QDate &newDateSoftwareBuild);

signals:
    void dayChanged();

    void monthChanged();

    void yearChanged();

    void dateSoftwareBuildChanged();

private:

    int m_day;
    int m_month;
    int m_year;
    QDate m_dateSoftwareBuild;
};

class GroupSensorCommParametters : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int address READ address WRITE setAddress NOTIFY addressChanged)
    Q_PROPERTY(int baudRate READ baudRate WRITE setBaudRate NOTIFY baudRateChanged)
    Q_PROPERTY(int charLength READ charLength WRITE setCharLength NOTIFY charLengthChanged)
    Q_PROPERTY(int parity READ parity WRITE setParity NOTIFY parityChanged)
    Q_PROPERTY(int stopBits READ stopBits WRITE setStopBits NOTIFY stopBitsChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)

public:

    int address() const;
    void setAddress(int newAddress);

    int baudRate() const;
    void setBaudRate(int newBaudRate);

    int charLength() const;
    void setCharLength(int newCharLength);

    int parity() const;
    void setParity(int newParity);

    int stopBits() const;
    void setStopBits(int newStopBits);

    const QString &password() const;
    void setPassword(const QString &newPassword);

signals:
    void addressChanged();

    void baudRateChanged();

    void charLengthChanged();

    void parityChanged();

    void stopBitsChanged();

    void passwordChanged();

private:

    int m_address;
    int m_baudRate;
    int m_charLength;
    int m_parity;
    int m_stopBits;
    QString m_password;
};

class GroupSensorValues : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int temperaturemv READ temperaturemv WRITE setTemperaturemv NOTIFY temperaturemvChanged)
    Q_PROPERTY(int temperatureDegrees READ temperatureDegrees WRITE setTemperatureDegrees NOTIFY temperatureDegreesChanged)
    Q_PROPERTY(int phasemv READ phasemv WRITE setPhasemv NOTIFY phasemvChanged)
    Q_PROPERTY(int phaseDegrees READ phaseDegrees WRITE setPhaseDegrees NOTIFY phaseDegreesChanged)
    Q_PROPERTY(int attenuationmv READ attenuationmv WRITE setattenuationmv NOTIFY attenuationmvChanged)
    Q_PROPERTY(int attenuationdb READ attenuationdb WRITE setAttenuationdb NOTIFY attenuationdbChanged)

public:

    int temperaturemv() const;
    void setTemperaturemv(int newTemperaturemv);

    int temperatureDegrees() const;
    void setTemperatureDegrees(int newTemperatureDegrees);

    Q_INVOKABLE int phasemv() const;
    Q_INVOKABLE void setPhasemv(int newPhasemv);

    int phaseDegrees() const;
    void setPhaseDegrees(int newPhaseDegrees);

    int attenuationmv() const;
    void setattenuationmv(int newAttenuationmv);

    int attenuationdb() const;
    void setAttenuationdb(int newAttenuationdb);

signals:
    void temperaturemvChanged();

    void temperatureDegreesChanged();

    void phasemvChanged();

    void phaseDegreesChanged();

    void attenuationmvChanged();

    void attenuationdbChanged();

private:

    int m_temperaturemv;
    int m_temperatureDegrees;
    int m_phasemv;
    int m_phaseDegrees;
    int m_attenuationmv;
    int m_attenuationdb;
};

class maParametters : public QObject
{
    Q_OBJECT
    Q_PROPERTY(GroupSerialNumber *serialNumber READ serialNumber WRITE setSerialNumber NOTIFY serialNumberChanged)
    Q_PROPERTY(QString sensorBoardName READ sensorBoardName WRITE setSensorBoardName NOTIFY sensorBoardNameChanged)
    Q_PROPERTY(GroupDateSoftware *dateSoftware READ dateSoftware WRITE setDateSoftware NOTIFY dateSoftwareChanged)
    Q_PROPERTY(GroupSensorCommParametters *sensorCommParametters READ sensorCommParametters WRITE setSensorCommParametters NOTIFY sensorCommParamettersChanged)
    Q_PROPERTY(GroupSensorValues *sensorValues READ sensorValues WRITE setsensorValues NOTIFY sensorValuesChanged)

public:
    explicit maParametters(QObject *parent = nullptr);

    GroupSerialNumber *serialNumber() const;
    void setSerialNumber(GroupSerialNumber *newSerialNumber);

    const QString &sensorBoardName() const;
    void setSensorBoardName(const QString &newSensorBoardName);

    GroupDateSoftware *dateSoftware() const;
    void setDateSoftware(GroupDateSoftware *newDateSoftware);

    GroupSensorCommParametters *sensorCommParametters() const;
    void setSensorCommParametters(GroupSensorCommParametters *newSensorCommParametters);

    GroupSensorValues *sensorValues() const;
    void setsensorValues(GroupSensorValues *newSensorValues);

signals:

    void serialNumberChanged();
    void sensorBoardNameChanged();
    void dateSoftwareChanged();
    void sensorCommParamettersChanged();

    void sensorValuesChanged();

private:
    GroupSerialNumber *m_serialNumber;
    QString m_sensorBoardName;
    GroupDateSoftware *m_dateSoftware;
    GroupSensorCommParametters *m_sensorCommParametters;
    GroupSensorValues *m_sensorValues = new GroupSensorValues;
};

#endif // MAPARAMETTERS_H
