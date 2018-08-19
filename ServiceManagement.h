#ifndef SERVICEMANAGEMENT_H
#define SERVICEMANAGEMENT_H

#include <QDialog>

namespace Ui {
class ServiceManagement;
}

class ServiceManagement : public QDialog
{
    Q_OBJECT

public:
    explicit ServiceManagement(QWidget *parent = nullptr);
    ~ServiceManagement();

private:
    Ui::ServiceManagement *ui;
};

#endif // SERVICEMANAGEMENT_H
