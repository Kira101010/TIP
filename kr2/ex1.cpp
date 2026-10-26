#include <iostream>
using namespace std;

// Рекурсивная функция возведения base в степень exp
long long fastPow(long long base, long long exp) {
    if (exp == 0)                        // база: любое число в степени 0 = 1
        return 1;

    if (exp % 2 == 0) {                  // если степень чётная
        long long half = fastPow(base, exp / 2);  // base^(exp/2)
        return half * half;              // возводим половину в квадрат
    } else {                             // если нечётная
        return base * fastPow(base, exp - 1);     // выносим одно основание
    }
}

int main() {
    long long a, n;                      // a — основание, n — степень
    cin >> a >> n;                       // читаем
    cout << fastPow(a, n);               // печатаем результат
    return 0;
}