#include "HousesDialog.h"
#include "ui_HousesDialog.h"

#include <QListWidgetItem>

HousesDialog::HousesDialog(DataList<House *> * houses, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HousesDialog)
{
    ui->setupUi(this);
    setModal(true);

    ui->areaLineEdit->setValidator(new QDoubleValidator(ui->areaLineEdit));
    ui->peoplesLineEdit->setValidator(new QIntValidator(ui->peoplesLineEdit));

    housesList = new DataList<House *>();
    for(int i = 0; i < houses->size(); ++i)
    {
        House * addingHouse = new House(houses->at(i));
        housesList->append(addingHouse);
        QListWidgetItem * item = new QListWidgetItem();
        item->setData(Qt::DisplayRole, addingHouse->getName());
        ui->housesListWidget->addItem(item);
    }

    connect(ui->addButton,        &QPushButton::clicked, this, &HousesDialog::addHouse   );
    connect(ui->removeButton,     &QPushButton::clicked, this, &HousesDialog::removeHouse);
    connect(ui->housesListWidget, &QListWidget::clicked, this, &HousesDialog::fillFields );
    connect(ui->saveButton,       &QPushButton::clicked, this, &HousesDialog::accept     );

    connect(ui->cancelButton,     &QPushButton::clicked, [this]()
    {
            delete housesList;
            reject();
    });
    connect(ui->houseLineEdit, &QLineEdit::textEdited, [this](QString text)
    {
        if (ui->housesListWidget->currentItem()->isSelected())
        {
            housesList->at(ui->housesListWidget->currentRow())->setName(text);
            ui->housesListWidget->currentItem()->setData(Qt::DisplayRole, text);
        }
    });
    connect(ui->adressLineEdit, &QLineEdit::textEdited, [this](QString text)
    {
        if (ui->housesListWidget->currentItem()->isSelected())
            housesList->at(ui->housesListWidget->currentRow())->setAdress(text);
    });
    connect(ui->areaLineEdit, &QLineEdit::textEdited, [this](QString text)
    {
        if (ui->housesListWidget->currentItem()->isSelected())
        {
            QLocale locale;
            housesList->at(ui->housesListWidget->currentRow())->setArea(locale.toFloat(text));
        }
    });
    connect(ui->peoplesLineEdit, &QLineEdit::textEdited, [this](QString text)
    {
        if (ui->housesListWidget->currentItem()->isSelected())
            housesList->at(ui->housesListWidget->currentRow())->setNumberOfPeoples(text.toInt());
    });
    connect(ui->privateHouseRadioButton, &QRadioButton::toggled, [this](bool value)
    {
        if (ui->housesListWidget->currentItem()->isSelected())
            housesList->at(ui->housesListWidget->currentRow())->setIsPrivate(value);
    });
}

HousesDialog::~HousesDialog()
{
    delete ui;
}

void HousesDialog::addHouse()
{
    House * house = new House();
    housesList->append(house);
    QListWidgetItem * item = new QListWidgetItem();
    item->setData(Qt::DisplayRole, house->getName());
    ui->housesListWidget->addItem(item);
}

void HousesDialog::removeHouse()
{
    auto index = ui->housesListWidget->currentRow();
    if (index != -1)
    {
        delete ui->housesListWidget->currentItem();
        housesList->removeAt(index);
        ui->housesListWidget->setCurrentRow(-1);
    }
}

void HousesDialog::fillFields()
{
    House * currentService = housesList->at(ui->housesListWidget->currentRow());
    ui->houseLineEdit->setText(currentService->getName());
    ui->adressLineEdit->setText(currentService->getAdress());
    ui->areaLineEdit->setText(QString::number(currentService->getArea()));
    ui->peoplesLineEdit->setText(QString::number(currentService->getNumberOfPeoples()));
    currentService->getIsPrivate() == true ? ui->privateHouseRadioButton->setChecked(true)
                                      : ui->apartmentHouseRadioButton->setChecked(true);
}

DataList<House *> * HousesDialog::getHousesList()
{
    return housesList;
}
