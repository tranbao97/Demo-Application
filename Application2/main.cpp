#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "AppMain.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    AppMain * appMain = new AppMain();
    appMain->initAppMain();

    return app.exec();
}
