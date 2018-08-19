#include "ServiceManagement.h"
#include "ui_ServiceManagement.h"

ServiceManagement::ServiceManagement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServiceManagement)
{
    ui->setupUi(this);

    setModal(true);
}

ServiceManagement::~ServiceManagement()
{
    delete ui;
}
