#include "ServicesDialog.h"
#include "ui_ServicesDialog.h"

#include <QListWidgetItem>

ServicesDialog::ServicesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServicesDialog)
{
    ui->setupUi(this);

    setModal(true);

    connect(ui->addButton,          &QPushButton::clicked, this, &ServicesDialog::AddService);
    connect(ui->removeButton,       &QPushButton::clicked, this, &ServicesDialog::RemoveService);
    connect(ui->servicesListWidget, &QListWidget::clicked, this, &ServicesDialog::fillFields);
}

ServicesDialog::~ServicesDialog()
{
    delete ui;
    for (auto item : servicesList)
        delete item;
}

void ServicesDialog::AddService()
{
    servicesList.push_back(new Services);
    ui->servicesListWidget->addItem(servicesList.back()->name);

    //ui->listView->setModel()

    /*QListWidgetItem * item = new QListWidgetItem(ui->servicesListWidget);
    item->setData(ServiceRole::name, "new sss");
    item->setData(ServiceRole::price, "0");
    item->setData(ServiceRole::meter, "true");
    item->setData(ServiceRole::unit, "m2");*/
}

void ServicesDialog::RemoveService()
{
   /* auto currentItem = ui->servicesListWidget->currentItem();
    if (currentItem)
        delete currentItem;*/
   //auto currentItem = ui->servicesListWidget->currentItem();
    auto currentItem = ui->servicesListWidget->currentItem();

}

void ServicesDialog::fillFields()
{
    auto currentItem = ui->servicesListWidget->currentItem();
    ui->serviceLineEdit->setText(currentItem->data(ServiceRole::name).toString());
    currentItem->data(ServiceRole::meter).toBool() == true ? ui->meterRadioButton->setChecked(true)
                                                           : ui->tariffRadioButton->setChecked(true);
}

