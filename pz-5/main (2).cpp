#include <iostream>
using namespace std;

int main() {
    double X, Y;
    cin >> X >> Y;

    double sum = X;
    int day = 1;

    // Сначала ВЫПОЛНЯЕМ тело, потом проверяем условие
    do {
        if (sum >= Y) {        // если уже достигли цели
            break;             // выходим
        }
        sum = sum * 1.1;       // +10%
        day = day + 1;         // следующий день
    } while (true);            // условие всегда true — выходим только через break

    cout << day;
    return 0;
}