#include "ipcsender.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ipcsender = new  class ipcsender("192.168.0.6");
    addButtons();

}

void MainWindow::addButtons()
{
    QPushButton *button = new QPushButton("&Power", this);
    button->setText("Off");
    connect(button, SIGNAL(clicked()), this, SLOT(yeet()));
}

void MainWindow::yeet()
{
   QPushButton *button = qobject_cast<QPushButton*>(sender());
   button->setText("On");
   char data[16] = {0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x39};
   ipcsender->sendIRRC(data);
}

MainWindow::~MainWindow()
{
    delete ui;
}


