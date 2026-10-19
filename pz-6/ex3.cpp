#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int n;
    cin >> s >> n;

    for (int step = 1; step < n; ++step) {   // n-1 переход
        string t;                           // новая строка-структура
        int i = 0;
        while (i < (int)s.size()) {
            int j = i;
            while (j < (int)s.size() && s[j] == s[i]) ++j;  // конец группы
            t += to_string(j - i);   // количество
            t += s[i];               // цифра
            i = j;
        }
        s = t;                       // переходим к следующей строке
    }

    cout << s << '\n';
    return 0;
}