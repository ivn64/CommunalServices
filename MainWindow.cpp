#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QMessageBox>

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
    fillHouses();

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

void MainWindow::fillHouses()
{
    ui->housesComboBox->clear();
    for(int i = 0; i < housesList->size(); ++i)
    {
        ui->housesComboBox->addItem(housesList->at(i)->getName());
    }
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
        fillHouses();
    }
}

void MainWindow::profitsDialogShow()
{
    if (ui->housesComboBox->currentIndex() >= 0)
    {
        ProfitsDialog profit(servicesList);
        if (profit.exec() == QDialog::Accepted)
        {
            housesList->at(ui->housesComboBox->currentIndex())->addProfitDate(profit.profitDate());
            housesList->save("houses.dat");
            fillHouses();
        }
    }
}
