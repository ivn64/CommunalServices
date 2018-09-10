#include "ServicesDialog.h"
#include "ui_ServicesDialog.h"

#include <QListWidgetItem>

ServicesDialog::ServicesDialog(DataList<Service *> * services, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServicesDialog)
{
    ui->setupUi(this);
    setModal(true);
    ui->unitComboBox->addItem("м2");
    ui->unitComboBox->addItem("м3");
    ui->unitComboBox->addItem("кВт*ч");
    ui->unitComboBox->setCurrentIndex(-1);

    ui->priceLineEdit->setValidator(new QDoubleValidator(ui->priceLineEdit));

    servicesList = new DataList<Service *>();
    for(int i = 0; i < services->size(); ++i)
    {
        Service * addingService = new Service(services->at(i));
        servicesList->append(addingService);
        QListWidgetItem * item = new QListWidgetItem();
        item->setData(Qt::DisplayRole, addingService->name);
        ui->servicesListWidget->addItem(item);
    }

    connect(ui->addButton,          &QPushButton::clicked, this, &ServicesDialog::addService   );
    connect(ui->removeButton,       &QPushButton::clicked, this, &ServicesDialog::removeService);
    connect(ui->servicesListWidget, &QListWidget::clicked, this, &ServicesDialog::fillFields   );
    //connect(ui->cancelButton,       &QPushButton::clicked, this, &ServicesDialog::reject);
    connect(ui->saveButton,         &QPushButton::clicked, this, &ServicesDialog::accept);

    connect(ui->cancelButton,       &QPushButton::clicked, [this]()
    {
            delete servicesList;
            reject();
    });

    connect(ui->serviceLineEdit, &QLineEdit::textEdited, [this](QString text)
    {
        if (ui->servicesListWidget->currentItem()->isSelected())
        {
            servicesList->at(ui->servicesListWidget->currentRow())->name = text;
            ui->servicesListWidget->currentItem()->setData(Qt::DisplayRole, text);
        }
    });
    connect(ui->priceLineEdit, &QLineEdit::textEdited, [this](QString text)
    {
        if (ui->servicesListWidget->currentItem()->isSelected())
        {
            QLocale locale;
            servicesList->at(ui->servicesListWidget->currentRow())->price = locale.toFloat(text);
        }
    });
    connect(ui->unitComboBox, &QComboBox::currentTextChanged, [this](QString text)
    {
        if (ui->servicesListWidget->currentItem()->isSelected())
            servicesList->at(ui->servicesListWidget->currentRow())->unit = text;
    });
    connect(ui->meterRadioButton, &QRadioButton::toggled, [this](bool value)
    {
        if (ui->servicesListWidget->currentItem()->isSelected())
            servicesList->at(ui->servicesListWidget->currentRow())->isMeter = value;
    });
}

ServicesDialog::~ServicesDialog()
{
    delete ui;
}

void ServicesDialog::addService()
{
    Service * service = new Service();
    servicesList->append(service);
    QListWidgetItem * item = new QListWidgetItem();
    item->setData(Qt::DisplayRole, service->name);
    ui->servicesListWidget->addItem(item);
}

void ServicesDialog::removeService()
{
    auto index = ui->servicesListWidget->currentRow();
    if (index != -1)
    {
        delete ui->servicesListWidget->currentItem();
        servicesList->removeAt(index);
        ui->servicesListWidget->setCurrentRow(-1);
    }
}

void ServicesDialog::fillFields()
{
    Service * currentService = servicesList->at(ui->servicesListWidget->currentRow());
    ui->serviceLineEdit->setText(currentService->name);
    currentService->isMeter == true ? ui->meterRadioButton->setChecked(true) : ui->tariffRadioButton->setChecked(true);
    ui->priceLineEdit->setText(QString::number(currentService->price));
    ui->unitComboBox->setCurrentText(currentService->unit);
}

void ServicesDialog::fillList()
{

}

DataList<Service *> *ServicesDialog::getServicesList()
{
    return servicesList;
}
