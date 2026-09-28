// Задача 1. Процедурный
// Задача 2. Процедурный

#include <iostream>
#include <cmath>

using namespace std;

void task1() {
    double a, b;
    cout << "Задача 1. Введите катеты a и b: ";
    cin >> a >> b;
    double c = sqrt(a * a + b * b);
    cout << "Гипотенуза: " << c << endl;
}

void task2() {
    double v, t;
    cout << "Задача 2. Введите скорость v и время t: ";
    cin >> v >> t;
    double s = v * t;
    const double L = 109.0;
    double pos = fmod(s, L);
    if (pos < 0) pos += L;
    cout << "Отметка: " << pos << endl;
}

int main() {
    task1();
    task2();
    return 0;
}
