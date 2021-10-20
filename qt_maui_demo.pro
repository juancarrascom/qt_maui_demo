QT += quick core serialbus serialport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        maparametters.cpp \
        microanalyzer.cpp \
        modbus.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

HEADERS += \
    maparametters.h \
    microanalyzer.h \
    modbus.h

TARGET = qt_maui_demo
    target.files =  qt_maui_demo
    target.path = /

INSTALLS += target
