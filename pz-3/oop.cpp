// Задача 1. Объектно-ориентированный
// Задача 2. Объектно-ориентированный

#include <iostream>
#include <cmath>

using namespace std;

class Triangle {
    double a, b;
public:
    Triangle(double a_, double b_) : a(a_), b(b_) {}
    double hypotenuse() const {
        return sqrt(a * a + b * b);
    }
};

class Biker {
    double v, t;
    static constexpr double L = 109.0;
public:
    Biker(double v_, double t_) : v(v_), t(t_) {}
    double position() const {
        double pos = fmod(v * t, L);
        if (pos < 0) pos += L;
        return pos;
    }
};

int main() {
    double a, b;
    cout << "Задача 1. Введите катеты a и b: ";
    cin >> a >> b;
    Triangle tri(a, b);
    cout << "Гипотенуза: " << tri.hypotenuse() << endl;

    double v, t;
    cout << "Задача 2. Введите скорость v и время t: ";
    cin >> v >> t;
    Biker biker(v, t);
    cout << "Отметка: " << biker.position() << endl;

    return 0;
}