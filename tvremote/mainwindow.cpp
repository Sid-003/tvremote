#include "ipcsender.h"
#include "mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ipcsender = new  class ipcsender("192.168.0.6");
    setupButtons();

}

void MainWindow::setupButtons()
{
     QButtonGroup *buttonGroup = this->findChildren<QButtonGroup*>("remoteButtons").first();
    connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton *)), this, SLOT(yeet(QAbstractButton *)));
}

void MainWindow::yeet(QAbstractButton *button)
{
    QString code = button->objectName();
    code.remove(0, 1);
    ipcsender->sendIRRC(code);
}

MainWindow::~MainWindow()
{
    delete ui;
}


