#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    servicesList = new DataList<Service *>();
    servicesList->load("test.txt");

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
        servicesList->removeAllItems();
        servicesList = services.getServicesList();
        servicesList->save("test.txt");
    }
}
