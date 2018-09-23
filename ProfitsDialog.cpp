#include "ProfitsDialog.h"
#include "ui_ProfitsDialog.h"

ProfitsDialog::ProfitsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfitsDialog)
{
    ui->setupUi(this);
}

ProfitsDialog::~ProfitsDialog()
{
    delete ui;
}
