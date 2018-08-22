#include "ServicesDialog.h"
#include "ui_ServicesDialog.h"

ServicesDialog::ServicesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServicesDialog)
{
    ui->setupUi(this);

    setModal(true);

    connect(ui->addButton,    &QPushButton::clicked, this, &ServicesDialog::AddService);
    connect(ui->removeButton, &QPushButton::clicked, this, &ServicesDialog::RemoveService);
}

ServicesDialog::~ServicesDialog()
{
    delete ui;
}

void ServicesDialog::AddService()
{
    Services * addingItem = new Services();
    servicesList.push_back(addingItem);
    ui->sevicesListWidget->addItem(addingItem->name);
}

void ServicesDialog::RemoveService()
{

    //servicesList.~DataList();


    auto currentItem = ui->sevicesListWidget->currentItem();
    if (currentItem)
        ui->sevicesListWidget->removeItemWidget(currentItem);


}

