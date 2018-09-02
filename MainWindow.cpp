#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->servicesButton, &QPushButton::clicked, []()
    {
        ServicesDialog services;
        if (services.exec() == QDialog::Accepted)
        {
            int test = 0;
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
