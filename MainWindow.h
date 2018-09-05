#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ServicesDialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void servicesDialogShow();

private:
    Ui::MainWindow *ui;
    DataList<Service *> * servicesList;

};

#endif // MAINWINDOW_H
