#ifndef SERVICESDIALOG_H
#define SERVICESDIALOG_H

#include <QDialog>
#include <QList>

#include "Service.h"
#include "ServicesList.h"

namespace Ui {
class ServicesDialog;
}

class ServicesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ServicesDialog(QWidget *parent = nullptr);
    ~ServicesDialog();

private:
    void addService();
    void removeService();
    void fillFields();

private:
    Ui::ServicesDialog *ui;
    ServicesList<Service *> * servicesList;
};

#endif // SERVICESDIALOG_H
