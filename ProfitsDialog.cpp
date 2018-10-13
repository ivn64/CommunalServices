#include "ProfitsDialog.h"
#include "ui_ProfitsDialog.h"

ProfitsDialog::ProfitsDialog(const DataList<Service *> * services, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProfitsDialog),
    m_services(services)
{
    ui->setupUi(this);

    ui->indicationsLineEdit->setValidator(new QDoubleValidator(ui->indicationsLineEdit));

    for(int i = 0; i < m_services->size(); ++i)
        ui->serviceComboBox->addItem(m_services->at(i)->getName());
    ui->serviceComboBox->setCurrentIndex(-1);

    connect(ui->serviceComboBox, QOverload<int>::of(&QComboBox::activated), [this](int index)
    {
        auto currentService = m_services->at(index);
        ui->tariffingLineEdit->setText(currentService->getIsMeter() ? "Счётчик" : "Тариф");
        ui->unitLabel->setText(currentService->getUnit());
        ui->costLineEdit->setText(QString::number(currentService->getPrice()));
    });

    connect(ui->cancelButton, &QPushButton::clicked, this, &QDialog::close);
}

ProfitsDialog::~ProfitsDialog()
{
    delete ui;
}
