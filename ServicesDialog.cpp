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

    servicesList = new ServicesList(this);

    servicesList1 = new ServicesList1();

    ui->servicesTableView->setModel(servicesList);

    ui->listWidget->setItemDelegate(new ServiceItemDelegate(this));

    connect(ui->addButton,         &QPushButton::clicked, this, &ServicesDialog::AddService   );
    connect(ui->removeButton,      &QPushButton::clicked, this, &ServicesDialog::RemoveService);
    connect(ui->servicesTableView, &QTableView::clicked,  this, &ServicesDialog::fillFields   );
    connect(ui->listWidget,        &QListWidget::clicked, this, &ServicesDialog::fillFields   );
}

ServicesDialog::~ServicesDialog()
{
    delete ui;
}

void ServicesDialog::AddService()
{
    Service service;
    servicesList->addService(service);
    Service service1;
    servicesList1->addService(service1);
    QListWidgetItem * item = new QListWidgetItem();
    item->setData(Services::Name, service1.name);
    item->setData(Services::IsMeter, service1.isMeter);
    item->setData(Services::Price, service1.price);
    item->setData(Services::Unit, service1.unit);
    ui->listWidget->addItem(item);
}

void ServicesDialog::RemoveService()
{
    QModelIndex index = ui->servicesTableView->selectionModel()->currentIndex();
    if (index.isValid())
        servicesList->removeService(index);
}

void ServicesDialog::fillFields()
{
    /*QModelIndex index = ui->servicesTableView->selectionModel()->currentIndex();
    if (index.isValid())
    {
        ui->serviceLineEdit->setText(servicesList->data(index).toString());
        servicesList->data(index).toBool() == true ? ui->meterRadioButton->setChecked(true)
                                                               : ui->tariffRadioButton->setChecked(true);

    }*/


    Service currentService = servicesList1->getService(ui->listWidget->currentRow());
    ui->serviceLineEdit->setText(currentService.name);
    currentService.isMeter == true ? ui->meterRadioButton->setChecked(true)
                                                : ui->tariffRadioButton->setChecked(true);
}

}

