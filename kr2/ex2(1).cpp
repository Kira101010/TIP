#include <iostream>
using namespace std;

// Рекурсивная функция поиска НОД(a, b)
long long gcd(long long a, long long b) {
    if (b == 0)              // база рекурсии: НОД(a, 0) = a
        return a;            //   возвращаем a и останавливаемся
    return gcd(b, a % b);    // иначе: НОД(a,b) = НОД(b, остаток a/b)
}

int main() {
    long long a, b;          // расходы Паши (a) и Егора (b)
    cin >> a >> b;           // читаем два числа
    cout << gcd(a, b);       // печатаем НОД — сумму сброса
    return 0;                // конец
}