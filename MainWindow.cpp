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
    fillYears();

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

//void MainWindow::fillDates()
//{
//    if (ui->housesComboBox->currentIndex() == -1)
//        return;
//    auto currentHouse = ui->housesComboBox->currentText();

//    auto it = std::find_if(housesList->begin(), housesList->end(), [currentHouse](const auto &item)
//    { return item->getName() == currentHouse; });
//    if (it != housesList->end())
//    {
//        auto currentHouse = *it;
//        auto profitsDate = currentHouse->getProfitsDate();
//        for (auto item : profitsDate)
//        {
//            auto addingYear = QString::number(item.getYear());
//            auto addingMonth = QString::number(item.getMonth());
//            if (ui->yearComboBox->findText(addingYear) == -1)
//                ui->yearComboBox->addItem(addingYear);
//            if (ui->monthComboBox->findText(addingMonth) == -1)
//                ui->monthComboBox->addItem(addingMonth);
//        }
//    }
//}

void MainWindow::fillYears()
{
    auto house = currentHouse();
    if (!house)
        return;
    for (auto item : house->getProfitsDate())
    {
        auto addingYear = QString::number(item.getYear());
        if (ui->yearComboBox->findText(addingYear) == -1)
            ui->yearComboBox->addItem(addingYear);
    }
}

void MainWindow::fillMonthes()
{
    auto house = currentHouse();
    if (!house)
        return;
    for (auto item : house->getProfitsDate())
    {
        auto currentYear = ui->yearComboBox->currentText();
        auto addingMonth = QString::number(item.getMonth());
        if (ui->monthComboBox->findText(addingMonth) == -1 &&  QString::number(item.getYear()) == currentYear)
            ui->monthComboBox->addItem(addingMonth);
    }
}

House * MainWindow::currentHouse()
{
    if (ui->housesComboBox->currentIndex() == -1)
        return nullptr;
    auto currentHouseName = ui->housesComboBox->currentText();
    auto it = std::find_if(housesList->begin(), housesList->end(), [currentHouseName](const auto &item)
    { return item->getName() == currentHouseName; });
    return it == housesList->end() ? nullptr : *it;
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
