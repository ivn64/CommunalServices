#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "DataList.h"
#include "Service.h"
#include "House.h"

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
    void housesDialogShow();
    void profitsDialogShow();

private:
    Ui::MainWindow *ui;
    DataList<Service *> * servicesList;
    DataList<House *> * housesList;

};

#endif // MAINWINDOW_H
