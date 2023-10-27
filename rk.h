#ifndef RK_H
#define RK_H

#include <vector>
#include <string>
#include <stdexcept>
// РЕШЕНИЕ УРАВНЕНИЙ

// описание результата отдного шага метода
struct step {
    double x, v; // подсчитанная точка
    double h; // шаг метода
    double le; // локальная погрешность
    double v2; // точка, вычисленная половинным шагом
    size_t C1, C2; // счетчики деления шага и удвоения шага
    step(double x, double v, double h, double le, double v2, size_t C1, size_t C2):
    x(x), v(v), h(h), le(le), v2(v2), C1(C1), C2(C2) {}
};
// шаг метода
std::pair<double, double> RK2(double (*f)(double, double), double x0, double u0, double h);
std::pair<double, double> RK4(double (*f)(double, double), double x0, double u0, double h);
// численное интегрирование
std::vector<step> solveIvp(double (*f)(double , double), double x0, double u0, double eps, double xMax, double borderEps,
                         const std::string& method, bool variableStep=true);

// РЕШЕНИЕ СИСТЕМ УРАВНЕНИЙ (ВТОРОГО ПОРЯДКА)


class Pair {
public:
    double first;
    double second;
    Pair(): first(0), second(0) {}
    Pair(double first, double second): first(first), second(second) {}

    double norm() {
        return std::max(std::abs(first), std::abs(second));
    } // возвращает норму
    Pair operator+(const Pair& p) const {
        Pair res(first + p.first, second + p.second);
        return res;
    }
    Pair operator-(const Pair& p) const {
        Pair res(first - p.first, second - p.second);
        return res;
    }
    Pair operator+(double x) const {
        Pair res(first + x, second + x);
        return res;
    }
    Pair operator*(double x) const {
        Pair res(first * x, second * x);
        return res;
    }
    Pair operator/(double x) const {
        Pair res(first / x, second / x);
        return res;
    }
};

// описание результата отдного шага метода
struct step_sys {
    double x;
    Pair v; // подсчитанная точка
    double h; // шаг метода
    double le; // локальная погрешность
    Pair v2; // точка, вычисленная половинным шагом
    size_t C1, C2; // счетчики деления шага и удвоения шага

    step_sys(double x, Pair v, double h, double le, Pair v2, size_t C1, size_t C2):
    x(x), v(v), h(h), le(le), v2(v2), C1(C1), C2(C2) {}
};
// шаг метода
std::pair<double, Pair> RK2_sys(Pair (*f)(double, Pair), double x0, Pair u0, double h);
std::pair<double, Pair> RK4_sys(Pair (*f)(double, Pair), double x0, Pair u0, double h);
std::vector<step_sys> solveIvp(Pair (*f)(double , Pair), double x0, Pair u0, double eps, double xMax, double borderEps,
                           const std::string& method, bool variableStep=true);


class Vec3 {
public:
    double first;
    double second;
    double third;
    Vec3(): first(0), second(0), third(0)  {}
    Vec3(double first, double second, double third): first(first), second(second), third(third) {}

    double norm() {
        return std::max(std::abs(first), std::max(std::abs(second), std::abs(third)));
    } // возвращает норму
    Vec3 operator+(const Vec3& p) const {
        Vec3 res(first + p.first, second + p.second, third + p.third);
        return res;
    }
    Vec3 operator-(const Vec3& p) const {
        Vec3 res(first - p.first, second - p.second, third - p.third);
        return res;
    }
    Vec3 operator+(double x) const {
        Vec3 res(first + x, second + x, third + x);
        return res;
    }
    Vec3 operator*(double x) const {
        Vec3 res(first * x, second * x, third * x);
        return res;
    }
    Vec3 operator/(double x) const {
        Vec3 res(first / x, second / x, third / x);
        return res;
    }
};

// описание результата отдного шага метода
struct step_sys3 {
    double x;
    Vec3 v; // подсчитанная точка
    double h; // шаг метода
    double le; // локальная погрешность
    Vec3 v2; // точка, вычисленная половинным шагом
    size_t C1, C2; // счетчики деления шага и удвоения шага

    step_sys3(double x, Vec3 v, double h, double le, Vec3 v2, size_t C1, size_t C2):
    x(x), v(v), h(h), le(le), v2(v2), C1(C1), C2(C2) {}
};
// шаг метода

std::pair<double, Vec3> RK4_sys3(Vec3 (*f)(double, Vec3), double x0, Vec3 u0, double h);
std::vector<step_sys3> solveIvp(Vec3 (*f)(double , Vec3), double x0, Vec3 u0, double eps, double xMax, double borderEps,
                           const std::string& method, bool variableStep=true, double h = 0.001);


#endif // RK_H
