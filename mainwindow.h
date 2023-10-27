#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QPushButton>
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QDesktopWidget>
#include <string>
#include "plotwindow.h"

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QFormLayout* form;
    QPushButton* solveButton;
    QPushButton* gridButton;
    QPushButton* clearButton;
    QLineEdit* field1;
    QLineEdit* field2;
    QLineEdit* field3;
    QLineEdit* field4;
    QLineEdit* field5;
    QLineEdit* field6;
    QLineEdit* field7;
    QLineEdit* field8;
    QLineEdit* field9;
    QLineEdit* field10;
    QLineEdit* field11;
    QLineEdit* field12;
    QLineEdit* field13;


    PlotWindow* pWindow;
private slots:
    void handleSolveButton();
    void handleGridButton();
    void handleClearButton();
};

#endif // MAINWINDOW_H
