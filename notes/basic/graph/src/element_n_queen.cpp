#include <bitset>
#include <iostream>

using namespace std;

const int N = 9;

int n;
char q[N][N];
bitset<N * 2> dg, udg;
bitset<N> col, row;

void dfs(int x, int y, int s) {
    if (s == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << q[i][j];
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int i = x; i < n; i++)
        for (int j = (i == x ? y : 0); j < n; j++)
            if (!row[i] && !col[j] && !dg[i + j] && !udg[n - i + j]) {
                q[i][j] = 'Q';
                row[i] = col[j] = dg[i + j] = udg[n - i + j] = 1;
                dfs(i, j + 1, s + 1);
                row[i] = col[j] = dg[i + j] = udg[n - i + j] = 0;
                q[i][j] = '.';
            }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            q[i][j] = '.';
    dfs(0, 0, 0);
    return 0;
}
