#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serviceDialog = new ServiceManagement(this);
    connect(ui->servicesButton, &QPushButton::clicked, serviceDialog, &QDialog::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}
