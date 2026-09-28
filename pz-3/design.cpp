// Задача 1. Проектный
// Задача 2. Проектный

#include <iostream>
#include <cmath>

using namespace std;

struct Task1 {
    double a, b;
    void input() {
        cout << "Задача 1. Введите катеты a и b: ";
        cin >> a >> b;
    }
    double solve() {
        return sqrt(a * a + b * b);
    }
    void output() {
        cout << "Гипотенуза: " << solve() << endl;
    }
};

struct Task2 {
    double v, t;
    void input() {
        cout << "Задача 2. Введите скорость v и время t: ";
        cin >> v >> t;
    }
    double solve() {
        const double L = 109.0;
        double pos = fmod(v * t, L);
        if (pos < 0) pos += L;
        return pos;
    }
    void output() {
        cout << "Отметка: " << solve() << endl;
    }
};

int main() {
    Task1 t1;
    t1.input();
    t1.output();

    Task2 t2;
    t2.input();
    t2.output();

    return 0;
}