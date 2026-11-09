#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> g(N, vector<char>(M));
    int si = 0, sj = 0, ei = 0, ej = 0;

    // читаем лабиринт и запоминаем, где старт (S) и выход (E)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'S') si = i, sj = j;
            if (g[i][j] == 'E') ei = i, ej = j;
        }

    // dp[i][j] = макс. число P до клетки (i,j); -1 = недостижимо
    vector<vector<int>> dp(N, vector<int>(M, -1));
    dp[si][sj] = 0; // на старте ничего не собрано

    // идём по сетке вниз-вправо
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            if (g[i][j] == '1') continue;      // стена
            if (i == si && j == sj) continue;  // старт уже задан

            // лучший результат среди соседей сверху и слева
            int best = -1;
            if (i > 0) best = max(best, dp[i - 1][j]);
            if (j > 0) best = max(best, dp[i][j - 1]);

            if (best < 0) continue;            // сюда не дойти

            // +1, если в клетке pdf
            dp[i][j] = best + (g[i][j] == 'P');
        }

    cout << dp[ei][ej] << "\n"; // ответ — в клетке выхода
    return 0;
}