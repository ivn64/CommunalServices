#ifndef SERVICESDIALOG_H
#define SERVICESDIALOG_H

#include <QDialog>
#include <QList>

#include "Services.h"

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
    void AddService();
    void RemoveService();

private:
    Ui::ServicesDialog *ui;
    QList<Services *> servicesList;
};

#endif // SERVICESDIALOG_H
