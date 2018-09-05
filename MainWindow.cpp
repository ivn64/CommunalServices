#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    servicesList = new DataList<Service *>();

    connect(ui->servicesButton, &QPushButton::clicked, this, &MainWindow::servicesDialogShow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::servicesDialogShow()
{
    ServicesDialog services(servicesList);
    if (services.exec() == QDialog::Accepted)
    {
        servicesList->save("test.txt");
    }
}
