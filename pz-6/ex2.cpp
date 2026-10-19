#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int w;
    cin >> w;

    // матрица символов: '*' или цифра-символ
    vector<vector<char>> a(n, vector<char>(m, '0'));

    for (int k = 0; k < w; ++k) {
        int r, c;
        cin >> r >> c;
        --r; --c;
        a[r][c] = '*';
    }

    int dr[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
    int dc[8] = {-1, 0, 1,-1, 1,-1, 0, 1};

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] == '*')
                for (int d = 0; d < 8; ++d) {
                    int ni = i + dr[d], nj = j + dc[d];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && a[ni][nj] != '*')
                        ++a[ni][nj];   // '0'..'8' — символы, ++ работает по ASCII
                }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << a[i][j];
        cout << '\n';
    }
    return 0;
}