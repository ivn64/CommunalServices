#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "ServicesDialog.h"
#include "HousesDialog.h"
#include "ProfitsDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    servicesList = new DataList<Service *>();
    servicesList->load("services.dat");

    housesList = new DataList<House *>();
    housesList->load("houses.dat");

    connect(ui->servicesButton, &QPushButton::clicked, this, &MainWindow::servicesDialogShow);
    connect(ui->housesButton,   &QPushButton::clicked, this, &MainWindow::housesDialogShow  );
    connect(ui->addButton,      &QPushButton::clicked, this, &MainWindow::profitsDialogShow );
}

MainWindow::~MainWindow()
{
    delete servicesList;
    delete housesList;
    delete ui;
}

void MainWindow::servicesDialogShow()
{
    ServicesDialog services(servicesList);
    if (services.exec() == QDialog::Accepted)
    {
        servicesList->removeAllItems();
        servicesList = services.getServicesList();
        servicesList->save("services.dat");
    }
}

void MainWindow::housesDialogShow()
{
    HousesDialog houses(housesList);
    if (houses.exec() == QDialog::Accepted)
    {
        housesList->removeAllItems();
        housesList = houses.getHousesList();
        housesList->save("houses.dat");
    }
}

void MainWindow::profitsDialogShow()
{
    ProfitsDialog profit(servicesList);
    if (profit.exec() == QDialog::Accepted)
    {
    int rr = 0;
    }
}
