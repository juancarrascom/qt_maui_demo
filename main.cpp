#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

#include "microanalyzer.h"
#include "maparametters.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    qputenv("QT_QPA_PLATFORM", "webgl");

    QGuiApplication app(argc, argv);

//    microAnalyzer *microshit = new microAnalyzer();
//    maParametters *paramshit = new maParametters();
//    GroupSensorValues *valshit = new GroupSensorValues();


    qmlRegisterType< GroupSensorValues >   ("MicroAnalyzer_Values",1,0,"MaControl_Values");
    qmlRegisterType< microAnalyzer >   ("MicroAnalyzer_Object",1,0,"MaControl_Object");
    qmlRegisterType< maParametters >   ("MicroAnalyzer",1,0,"MaControl");


    QQmlApplicationEngine engine;

//    engine.rootContext()->setContextProperty("microshit",microshit);
//    engine.rootContext()->setContextProperty("paramshit",paramshit);
//    engine.rootContext()->setContextProperty("valshit",valshit);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
