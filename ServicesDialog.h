#ifndef SERVICESDIALOG_H
#define SERVICESDIALOG_H

#include <QDialog>
#include <QList>

#include "Service.h"
#include "DataList.h"

namespace Ui {
class ServicesDialog;
}

class ServicesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ServicesDialog(DataList<Service *> * services, QWidget *parent = nullptr);
    ~ServicesDialog();
    DataList<Service *> * getServicesList();

private:
    void addService();
    void removeService();
    void fillFields();

private:
    Ui::ServicesDialog *ui;
    DataList<Service *> * servicesList;
};

#endif // SERVICESDIALOG_H
