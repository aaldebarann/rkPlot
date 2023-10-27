#include "plotwindow.h"

#define TOSTRS(x) (doubleToScientificString(x).c_str())
#define TOSTR(x) (std::to_string(x).c_str())
#define str(x) (std::to_string(x)).c_str()

PlotWindow::PlotWindow(QWidget *parent) :
    QMainWindow(parent)
{
    g = 9.80665;
    setWindowTitle("Решение");
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    form = new QVBoxLayout(centralWidget);

    table = new QTableWidget(this);
    table->verticalHeader()->setVisible(false);
    table->setColumnCount(9);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    chart = new QChart();
    chart->legend()->setVisible(false);
    chart->setTitle("численное решение (omega(x), phi(x))");

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    form->addWidget(chartView);
    // Pair u0(1, 0);
    // std::vector<step_sys> v = solveIvp(function, 0, u0, 1e-3, 30, 0.01, "RK4", false);

}

void PlotWindow::plot() {
    Vec3 u0(omega_0, phi_0, ddt_phi_0);
    std::vector<step_sys3> v = solveIvp(fun, x0, u0, eps, xMax, borderEps, "RK4", true);

    QLineSeries *approximateSeries = new QLineSeries();
    approximateSeries->setColor(QColor(247, 82, 0));
    // approximateSeries->setName("численное решение y=u(x)");
    // approximateSeries->setMarkerSize(8);
    for (auto s: v)
    {
        approximateSeries->append(s.v.first, s.v.second);
    }
    // chart->setAnimationOptions (QChart :: AllAnimations);
    chart->setAnimationOptions (QChart ::NoAnimation);
    chart->setLocalizeNumbers (true);
    chart->addSeries(approximateSeries);
    chart->createDefaultAxes();
    chart->axisX()->setTitleText("omega");
    chart->axisY()->setTitleText("phi");




    table->clear();

    QStringList* headers = new QStringList();
    (*headers) << "Итерация" << "x" << "v" << "v2" << "v - v2"<<"ОЛП" << "Шаг" << "Деления шага" << "Удвоения шага";
    table->setHorizontalHeaderLabels(*headers);
    table->setRowCount(v.size());
    int i = 0;
    for(auto s: v) {
        table->setItem(i, 0, new QTableWidgetItem(TOSTR(i)));
        table->setItem(i, 1, new QTableWidgetItem(TOSTR(s.x)));
        table->setItem(i, 2, new QTableWidgetItem(TOSTR(s.v.first)));
        table->setItem(i, 3, new QTableWidgetItem(TOSTR(s.v2.first)));
        table->setItem(i, 4, new QTableWidgetItem(TOSTRS(s.v.first - s.v2.first)));
        table->setItem(i, 5, new QTableWidgetItem(TOSTRS(s.le)));
        table->setItem(i, 6, new QTableWidgetItem(TOSTRS(s.h)));
        table->setItem(i, 7, new QTableWidgetItem(TOSTR(s.C1)));
        table->setItem(i, 8, new QTableWidgetItem(TOSTR(s.C2)));
        i++;
    }

    form->addWidget(table);
}

PlotWindow::~PlotWindow()
{


}
