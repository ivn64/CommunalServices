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
    connect(ui->indicationsLineEdit, &QLineEdit::textEdited, [this]()
    {
        ui->accuralsLineEdit->setText(QString::number(ui->indicationsLineEdit->text().toFloat() * ui->costLineEdit->text().toFloat()));
    });
    connect(ui->addButton, &QPushButton::clicked, [this]()
    {
        fillProfitDate();
        this->accept();
    });
    connect(ui->cancelButton, &QPushButton::clicked, this, &QDialog::reject);
}

ProfitsDialog::~ProfitsDialog()
{
    delete ui;
}

void ProfitsDialog::fillProfitDate()
{
    Profit profit;
    profit.setService(ui->serviceComboBox->currentText());
    profit.setIndications(ui->indicationsLineEdit->text().toFloat());
    profit.setUnit(ui->unitLabel->text());
    profit.setCost(ui->costLineEdit->text().toFloat());
    profit.setAccruals(ui->accuralsLineEdit->text().toFloat());

    m_profitDate.setMonth(ui->monthComboBox->currentIndex());
    m_profitDate.setYear(ui->yearComboBox->currentText().toInt());
    m_profitDate.addProfit(profit);
}
