#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> a(N, vector<int>(M)); // баллы
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> a[i][j];

    // dp[i][j] = макс. сумма до клетки (i,j)
    vector<vector<int>> dp(N, vector<int>(M));
    dp[0][0] = a[0][0];

    for (int j = 1; j < M; j++) dp[0][j] = dp[0][j - 1] + a[0][j]; // первая строка
    for (int i = 1; i < N; i++) dp[i][0] = dp[i - 1][0] + a[i][0]; // первый столбец

    // остальные: сверху или слева — берём максимум
    for (int i = 1; i < N; i++)
        for (int j = 1; j < M; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];

    // восстанавливаем путь с финиша к старту
    vector<pair<int, int>> path;
    int i = N - 1, j = M - 1;

    while (true) {
        path.push_back({i, j});
        if (i == 0 && j == 0) break;
        if (i == 0) j--;
        else if (j == 0) i--;
        else {
            if (dp[i - 1][j] > dp[i][j - 1]) i--;
            else j--;
        }
    }

    reverse(path.begin(), path.end()); // от старта к финишу

    for (auto p : path)
        cout << p.first << " " << p.second << "\n";

    return 0;
}