#ifndef PROFITSDIALOG_H
#define PROFITSDIALOG_H

#include <QDialog>

namespace Ui {
class ProfitsDialog;
}

class ProfitsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProfitsDialog(QWidget *parent = nullptr);
    ~ProfitsDialog();

private:
    Ui::ProfitsDialog *ui;
};

#endif // PROFITSDIALOG_H
