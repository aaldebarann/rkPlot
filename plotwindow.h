#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <QMainWindow>
#include <QFormLayout>
#include <cmath>
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>
#include <QtCharts>
#include <string>
#include <cstring>
#include <charconv>
#include <sstream>
#include <iomanip>
#include <QTableWidget>
#include <QHeaderView>
#include "rk.h"

class PlotWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlotWindow(QWidget *parent = nullptr);
    void plot();
    ~PlotWindow();

    static double omega_0, phi_0, ddt_phi_0;
    static double k, F, J, n, m, b, g;
    static double x0, xMax, borderEps, eps;
    QChart* chart;

private:

    QVBoxLayout* form;
    QChartView *chartView;
    QTableWidget* table;

    static Pair function(double x, Pair u) {
        return {u.second, -std::sin(u.first)};
    }
    static Vec3 fun(double x, Vec3 u) {
        /*
         * first = omega
         * second = phi
         * third = d phi / dt
         */
        double first = (k*std::cos(u.second) - F) / J;
        double second = u.third;
        double third = n*n*u.first*u.first*std::sin(u.second)* std::cos(u.second)
                - g * std::sin(u.second) - b * u.third / m;
        return {first, second, third};
    }
    std::string doubleToScientificString(double value) {
        std::ostringstream oss;
        oss << std::scientific << std::setprecision(6) << value;
        return oss.str();
    }
};

#endif // PLOTWINDOW_H
