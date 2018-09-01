#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    servicesDialog = new Services::ServicesDialog(this);
    connect(ui->servicesButton, &QPushButton::clicked, servicesDialog, &QDialog::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}
