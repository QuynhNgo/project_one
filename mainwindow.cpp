#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->widget->resolution = value;
}

void MainWindow::resolution()
{
        ui->widget->resolution = ui->horizontalSlider->value();
        ui->widget->updateGL();
}
