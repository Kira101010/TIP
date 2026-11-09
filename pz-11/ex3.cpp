#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int N, K, L;
    cin >> N >> K >> L;

    vector<int> a(N);
    for (int &x : a) cin >> x;

    sort(a.rbegin(), a.rend()); // дорогие впереди

    map<int, int> used; // сколько каждого вида уже взяли
    long long sum = 0;
    int taken = 0;

    for (int x : a) {
        if (taken == K) break;   // набрали K
        if (used[x] < L) {       // не больше L одинаковых
            used[x]++;
            sum += x;
            taken++;
        }
    }

    cout << sum << "\n";
    return 0;
}