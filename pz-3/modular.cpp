// Задача 1. Модульный
// Задача 2. Модульный

#include <iostream>
#include <cmath>

using namespace std;

namespace geometry {
    double hypotenuse(double a, double b) {
        return sqrt(a * a + b * b);
    }
}

namespace road {
    double position(double v, double t) {
        const double L = 109.0;
        double s = v * t;
        double pos = fmod(s, L);
        if (pos < 0) pos += L;
        return pos;
    }
}

int main() {
    double a, b;
    cout << "Задача 1. Введите катеты a и b: ";
    cin >> a >> b;
    cout << "Гипотенуза: " << geometry::hypotenuse(a, b) << endl;

    double v, t;
    cout << "Задача 2. Введите скорость v и время t: ";
    cin >> v >> t;
    cout << "Отметка: " << road::position(v, t) << endl;

    return 0;
}