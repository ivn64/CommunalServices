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

    ui->listWidget->setItemDelegate(new ServiceItemDelegate(this));

    connect(ui->addButton,         &QPushButton::clicked, this, &ServicesDialog::AddService   );
    connect(ui->removeButton,      &QPushButton::clicked, this, &ServicesDialog::RemoveService);
    connect(ui->listWidget,        &QListWidget::clicked, this, &ServicesDialog::fillFields   );
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
    ui->listWidget->addItem(item);
}

void ServicesDialog::RemoveService()
{
    auto index = ui->listWidget->currentRow();
    if (index != -1)
    {
        delete ui->listWidget->currentItem();
        servicesList->removeService(ui->listWidget->currentRow());
        ui->listWidget->setCurrentRow(-1);
    }
}

void ServicesDialog::fillFields()
{
    Service * currentService = servicesList->getService(ui->listWidget->currentRow());
    ui->serviceLineEdit->setText(currentService->name);
    currentService->isMeter == true ? ui->meterRadioButton->setChecked(true)
                                                : ui->tariffRadioButton->setChecked(true);
}

}

