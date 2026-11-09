#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, D;
    cin >> N >> D;

    vector<int> a(N);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());

    // можно ли уложиться в D дней при разнице <= x
    auto ok = [&](int x) {
        int groups = 1, start = 0;
        for (int i = 1; i < N; i++) {
            if (a[i] - a[start] > x) { groups++; start = i; } // новый день
        }
        return groups <= D;
    };

    int l = 0, r = a.back() - a.front();
    while (l < r) {
        int mid = (l + r) / 2;
        if (ok(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << "\n";
    return 0;
}