#ifndef PROFITSDIALOG_H
#define PROFITSDIALOG_H

#include <QDialog>

#include "Service.h"
#include "DataList.h"

namespace Ui {
class ProfitsDialog;
}

class ProfitsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProfitsDialog(const DataList<Service *> * services, QWidget *parent = nullptr);
    ~ProfitsDialog();

private:
    Ui::ProfitsDialog *ui;
    const DataList<Service *> * m_services;
};

#endif // PROFITSDIALOG_H
