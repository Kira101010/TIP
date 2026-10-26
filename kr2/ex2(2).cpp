#include <iostream>
using namespace std;

// Итеративная функция поиска НОД(a, b)
long long gcd(long long a, long long b) {
    while (b != 0) {         // пока второе число не ноль — продолжаем
        long long temp = b;  // запоминаем b во временную переменную
        b = a % b;           // новое b = остаток от деления a на b
        a = temp;            // новое a = старое b
    }
    return a;                // когда b стал нулём, a — это НОД
}

int main() {
    long long a, b;          // расходы Паши (a) и Егора (b)
    cin >> a >> b;           // читаем два числа
    cout << gcd(a, b);       // печатаем НОД — сумму сброса
    return 0;                // конец
}