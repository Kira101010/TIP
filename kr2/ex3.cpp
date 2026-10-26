#include <iostream>
using namespace std;

// Перекладываем n ингредиентов со стержня from на to через aux
void hanoi(int n, int from, int to, int aux) {
    if (n == 0)                                  // база: перекладывать нечего
        return;

    hanoi(n - 1, from, aux, to);                 // шаг 1: n-1 верхних → на aux
    cout << "Ingredient " << n                   // шаг 2: печатаем инструкцию
         << " move from " << from                //   для самого большого
         << " to " << to << endl;                //   с from на to
    hanoi(n - 1, aux, to, from);                 // шаг 3: n-1 с aux → на to
}

int main() {
    int n;                                       // количество ингредиентов
    cin >> n;                                    // читаем n
    hanoi(n, 1, 3, 2);                           // перекладываем с 1 на 3 через 2
    return 0;
}