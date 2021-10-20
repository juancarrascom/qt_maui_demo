#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "microanalyzer.h"
#include "maparametters.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    qputenv("QT_QPA_PLATFORM", "webgl");

    QGuiApplication app(argc, argv);



    microAnalyzer* m_device = new microAnalyzer();
    m_device->readData();

    qmlRegisterType< GroupSensorValues >   ("MicroAnalyzer",1,0,"MaControl");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
