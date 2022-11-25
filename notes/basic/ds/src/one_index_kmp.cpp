#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;

int n, m;
char p[N], s[M];
int ne[N];

int main() {
    cin >> n >> p + 1 >> m >> s + 1;  // 1-based index.

    // find ne.
    // i = 2, because ne[1] = 0
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;
        ne[i] = j;
    }

    // matching process.
    for (int i = 1, j = 0; i <= m; i++) {
        // j emulate all possible position in pattern string.
        while (j && s[i] != p[j + 1]) {
            // not match.
            j = ne[j];  // move j.
            // try to see if p[i - j: i + m] == s[i: i + m]
        }
        if (s[i] == p[j + 1]) j++;  // matched 1 char. if we don't
        // j == 0, then just advance to next position in s.
        if (j == n) {
            cout << i - j << " ";  // success.
            j = ne[j];             // match again
        }
    }
    cout << endl;
    return 0;
}