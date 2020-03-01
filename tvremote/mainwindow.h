#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ipcsender.h"

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setupButtons();

public slots:
    void yeet(QAbstractButton *button);
private:
    ipcsender *ipcsender;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
