#ifndef SERVICESDIALOG_H
#define SERVICESDIALOG_H

#include <QDialog>
#include <QList>

#include "Service.h"
#include "ServicesList.h"

namespace Ui {
class ServicesDialog;
}

namespace Services {

enum ThemeItemRole
{
      Name = Qt::UserRole + 1
    , IsMeter
    , Unit
    , Price
};

class ServicesDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ServicesDialog(QWidget *parent = nullptr);
    ~ServicesDialog();

private:
    void AddService();
    void RemoveService();
    void fillFields();

private:
    Ui::ServicesDialog *ui;
    ServicesList * servicesList;
};

}

#endif // SERVICESDIALOG_H
