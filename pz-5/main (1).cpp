#include <iostream>
using namespace std;

int main() {
    double X, Y;
    cin >> X >> Y;

    double sum = X;       // сумма в текущий день
    int day = 1;          // текущий день

    // Пока сумма МЕНЬШЕ Y — продолжаем увеличивать
    while (sum < Y) {
        sum = sum * 1.1;   // +10% к сумме
        day = day + 1;     // следующий день
    }

    cout << day;
    return 0;
}