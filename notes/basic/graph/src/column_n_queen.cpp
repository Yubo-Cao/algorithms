#include <bitset>
#include <iostream>

using namespace std;

const int N = 9;

int n;
char q[N][N];
bitset<N> col;
bitset<2 * N> dg, udg;

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << q[i][j];
                if (j < n - 1) cout << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
            q[u][i] = 'q';
            col[i] = dg[u + i] = udg[n - u + i] = 1;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = 0;
            q[u][i] = '.';
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            q[i][j] = '.';
    dfs(0);
    return 0;
}
