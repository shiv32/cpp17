#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "pdfitem.h"
#include <QDir>

int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);
    qmlRegisterType<PdfItem>("CustomPdf", 1, 0, "PdfItem");

     QQmlApplicationEngine engine;
    // engine.load(QUrl::fromLocalFile("qml/main.qml"));

    engine.load(QUrl::fromLocalFile(
    QDir(QCoreApplication::applicationDirPath()).filePath("qml/main.qml")));


    return app.exec();
}
