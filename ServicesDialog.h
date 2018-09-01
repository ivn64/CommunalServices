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

    enum ServiceRole
    {
        name = Qt::UserRole + 1,
        meter,
        unit,
        price
    };

public:
    explicit ServicesDialog(QWidget *parent = nullptr);
    ~ServicesDialog();

private:
    void AddService();
    void RemoveService();
    void fillFields();

private:
    Ui::ServicesDialog *ui;
    QList<Service *> servicesList;
    ServicesList * dataList;
};

#endif // SERVICESDIALOG_H
