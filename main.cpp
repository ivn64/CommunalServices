#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QFile file(":/style.qss");
    if (file.open(QFile::ReadOnly))
        app.setStyleSheet(file.readAll());
    MainWindow w;
    w.show();

    return app.exec();
}
