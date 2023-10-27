#include "mainwindow.h"

#define str(x) (std::to_string(x)).c_str()


double PlotWindow::omega_0, PlotWindow::phi_0, PlotWindow::ddt_phi_0;
double PlotWindow::k, PlotWindow::F, PlotWindow::J, PlotWindow::n, PlotWindow::m, PlotWindow::b, PlotWindow::g;
double PlotWindow::x0, PlotWindow::xMax, PlotWindow::borderEps, PlotWindow::eps;

void MainWindow::handleSolveButton() {
    // change the text
    // TODO: if numx is too small, print it in exponent form
    double num1 = field1->text().toDouble();
    field1->setText(str(num1));
    pWindow->omega_0 = num1;
    double num2 = field2->text().toDouble();
    field2->setText(str(num2));
    pWindow->phi_0 = num2;
    double num3 = field3->text().toDouble();
    field3->setText(str(num3));
    pWindow->ddt_phi_0 = num3;
    double num4 = field4->text().toDouble();
    field4->setText(str(num4));
    pWindow->k = num4;

    pWindow->F = field5->text().toDouble();
    field5->setText(str(pWindow->F));

    pWindow->J = field6->text().toDouble();
    field6->setText(str(pWindow->J));

    pWindow->n = field7->text().toDouble();
    field7->setText(str(pWindow->n));

    pWindow->m = field8->text().toDouble();
    field8->setText(str(pWindow->m));

    pWindow->b = field9->text().toDouble();
    field9->setText(str(pWindow->b));

    pWindow->x0 = field10->text().toDouble();
    field10->setText(str(pWindow->x0));

    pWindow->xMax = field11->text().toDouble();
    field11->setText(str(pWindow->xMax));

    pWindow->borderEps = field12->text().toDouble();
    field12->setText(str(pWindow->borderEps));

    pWindow->eps = field13->text().toDouble();
    field13->setText(str(pWindow->eps));

    std::string s = "exapmle" + std::to_string(num1)+ std::to_string(num2);
    // TODO: add data series


    pWindow->show();
    pWindow->plot();
}
void MainWindow::handleGridButton() {
    // change the text
    // TODO: if numx is too small, print it in exponent form
    pWindow->show();

    double num1 = field1->text().toDouble();
    field1->setText(str(num1));
    //pWindow->omega_0 = num1;
    double num2 = field2->text().toDouble();
    field2->setText(str(num2));
    //pWindow->phi_0 = num2;
    double num3 = field3->text().toDouble();
    field3->setText(str(num3));
    //pWindow->ddt_phi_0 = num3;
    double num4 = field4->text().toDouble();
    field4->setText(str(num4));
    pWindow->k = num4;

    pWindow->F = field5->text().toDouble();
    field5->setText(str(pWindow->F));

    pWindow->J = field6->text().toDouble();
    field6->setText(str(pWindow->J));

    pWindow->n = field7->text().toDouble();
    field7->setText(str(pWindow->n));

    pWindow->m = field8->text().toDouble();
    field8->setText(str(pWindow->m));

    pWindow->b = field9->text().toDouble();
    field9->setText(str(pWindow->b));

    pWindow->x0 = field10->text().toDouble();
    field10->setText(str(pWindow->x0));

    pWindow->xMax = field11->text().toDouble();
    field11->setText(str(pWindow->xMax));

    pWindow->borderEps = field12->text().toDouble();
    field12->setText(str(pWindow->borderEps));

    pWindow->eps = field13->text().toDouble();
    field13->setText(str(pWindow->eps));

    std::string s = "exapmle" + std::to_string(num1)+ std::to_string(num2);
    // TODO: add data series
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            pWindow->omega_0 = num1 + (4 - i)*0.25;
            pWindow->phi_0 = num2 + (4 - j)*0.25;
            pWindow->ddt_phi_0 = num3;
            pWindow->plot();
        }
    }

}

void MainWindow::handleClearButton() {
    pWindow->chart->removeAllSeries();
}

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
{
    pWindow = new PlotWindow();
    setWindowTitle("Постановка задачи Коши");
    pWindow->setWindowTitle("Решение");
    pWindow->resize(960, 540);

    form = new QFormLayout(this);

    field1 = new QLineEdit(this);
    field2 = new QLineEdit(this);
    field3 = new QLineEdit(this);
    field4 = new QLineEdit(this);
    field5 = new QLineEdit(this);
    field6 = new QLineEdit(this);
    field7 = new QLineEdit(this);
    field8 = new QLineEdit(this);
    field9 = new QLineEdit(this);
    field10 = new QLineEdit(this);
    field11 = new QLineEdit(this);
    field12 = new QLineEdit(this);
    field13 = new QLineEdit(this);
    field10->setText(str(0));
    field11->setText(str(4));
    field12->setText(str(0.1));
    field13->setText(str(1e-6));
    field1->setText(str(1));
    field2->setText(str(1));
    field3->setText(str(0));
    field4->setText(str(1));
    field5->setText(str(1));
    field6->setText(str(1));
    field7->setText(str(1));
    field8->setText(str(1));
    field9->setText(str(1));
    form->addRow("x0 = ", field10);
    form->addRow("omega(x0) = ", field1);
    form->addRow("phi(x0) = ", field2);
    form->addRow("(d/dt) phi(x0) = ", field3);
    form->addRow("eps = ", field13);
    form->addRow("xMax = ", field11);
    form->addRow("borderEps = ", field12);
    form->addRow("k = ", field4);
    form->addRow("F = ", field5);
    form->addRow("J = ", field6);
    form->addRow("n = ", field7);
    form->addRow("m = ", field8);
    form->addRow("b = ", field9);
    solveButton = new QPushButton("Построить решение", this);
    connect(solveButton, &QPushButton::released, this, &MainWindow::handleSolveButton);
    form->addRow(solveButton);
    gridButton = new QPushButton("Построить фазовый портрет в окрестности точки", this);
    connect(gridButton, &QPushButton::released, this, &MainWindow::handleGridButton);
    form->addRow(gridButton);
    clearButton = new QPushButton("Очистить", this);
    connect(clearButton, &QPushButton::released, this, &MainWindow::handleClearButton);
    form->addRow(clearButton);
}

MainWindow::~MainWindow()
{
}

