#ifndef HOUSESDIALOG_H
#define HOUSESDIALOG_H

#include <QDialog>

#include "House.h"
#include "DataList.h"

namespace Ui {
class HousesDialog;
}

class HousesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HousesDialog(DataList<House *> * houses, QWidget *parent = nullptr);
    ~HousesDialog();
    DataList<House *> * getHousesList();

private:
    void addHouse();
    void removeHouse();
    void fillFields();
    void fillList();

private:
    Ui::HousesDialog *ui;
    DataList<House *> * housesList;

};

#endif // HOUSESDIALOG_H
