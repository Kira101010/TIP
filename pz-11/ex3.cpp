#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int N, K, L;
    cin >> N >> K >> L; // N растений, K в букете, не больше L одинаковых

    vector<int> a(N);
    for (int &x : a) cin >> x; // читаем стоимости

    sort(a.rbegin(), a.rend()); // сортируем по убыванию — дорогие впереди

    map<int, int> used; // used[x] = сколько растений со стоимостью x уже взяли
    long long sum = 0;  // сумма букета (long long — вдруг числа большие)
    int taken = 0;      // сколько растений уже взяли

    for (int x : a) {           // идём по растениям от дорогих к дешёвым
        if (taken == K) break;  // набрали K — дальше не нужно
        if (used[x] < L) {      // этого вида взяли меньше L — можно взять
            used[x]++;          // отмечаем, что взяли ещё одно
            sum += x;           // добавляем стоимость
            taken++;            // увеличиваем счётчик взятых
        }
        // если used[x] == L — пропускаем, идём к следующему растению
    }

    cout << sum << "\n";
    return 0;
}