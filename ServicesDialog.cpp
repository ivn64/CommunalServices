#include "ServicesDialog.h"
#include "ui_ServicesDialog.h"

#include <QListWidgetItem>

#include "ServicesList.h"

ServicesDialog::ServicesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServicesDialog)
{
    ui->setupUi(this);

    setModal(true);

    servicesList = new ServicesList(this);

    ui->servicesTableView->setModel(servicesList);

    connect(ui->addButton,          &QPushButton::clicked, this, &ServicesDialog::AddService);
    connect(ui->removeButton,       &QPushButton::clicked, this, &ServicesDialog::RemoveService);
    connect(ui->servicesTableView,  &QTableView::clicked, this, &ServicesDialog::fillFields);
}

ServicesDialog::~ServicesDialog()
{
    delete ui;
}

void ServicesDialog::AddService()
{
    Service service;
    servicesList->addService(service);
}

void ServicesDialog::RemoveService()
{
    QModelIndex index = ui->servicesTableView->selectionModel()->currentIndex();
    if (index.isValid())
        servicesList->removeService(index);
}

void ServicesDialog::fillFields()
{
    QModelIndex index = ui->servicesTableView->selectionModel()->currentIndex();
    if (index.isValid())
    {
        ui->serviceLineEdit->setText(servicesList->data(index).toString());
        servicesList->data(index).toBool() == true ? ui->meterRadioButton->setChecked(true)
                                                               : ui->tariffRadioButton->setChecked(true);

    }
}

