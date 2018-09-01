#include "ServicesDialog.h"
#include "ui_ServicesDialog.h"

#include <QListWidgetItem>

#include "ServiceItemDelegate.h"

namespace Services {

ServicesDialog::ServicesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServicesDialog)
{
    ui->setupUi(this);

    setModal(true);

    servicesList = new ServicesList();

    ui->servicesListWidget->setItemDelegate(new ServiceItemDelegate(this));

    connect(ui->addButton,          &QPushButton::clicked, this, &ServicesDialog::AddService   );
    connect(ui->removeButton,       &QPushButton::clicked, this, &ServicesDialog::RemoveService);
    connect(ui->servicesListWidget, &QListWidget::clicked, this, &ServicesDialog::fillFields   );
}

ServicesDialog::~ServicesDialog()
{
    delete ui;
}

void ServicesDialog::AddService()
{
    Service service;
    servicesList->addService(new Service);
    QListWidgetItem * item = new QListWidgetItem();
    item->setData(Services::Name, service.name);
    item->setData(Services::IsMeter, service.isMeter);
    item->setData(Services::Price, service.price);
    item->setData(Services::Unit, service.unit);
    ui->servicesListWidget->addItem(item);
}

void ServicesDialog::RemoveService()
{
    auto index = ui->servicesListWidget->currentRow();
    if (index != -1)
    {
        delete ui->servicesListWidget->currentItem();
        servicesList->removeService(ui->servicesListWidget->currentRow());
        ui->servicesListWidget->setCurrentRow(-1);
    }
}

void ServicesDialog::fillFields()
{
    Service * currentService = servicesList->getService(ui->servicesListWidget->currentRow());
    ui->serviceLineEdit->setText(currentService->name);
    currentService->isMeter == true ? ui->meterRadioButton->setChecked(true)
                                                : ui->tariffRadioButton->setChecked(true);
}

}

