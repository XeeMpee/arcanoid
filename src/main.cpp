#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQuickItem>
#include <QQuickView>
#include <QQmlComponent>

#include "spdlog/spdlog.h"


int main(int argc, char *argv[])
{
    spdlog::info("Application running...");
    QGuiApplication app(argc, argv);

    QQuickView view{};
    view.setSource(QUrl("qrc:///qml/Main.qml"));

    view.show();
    return app.exec();
}
