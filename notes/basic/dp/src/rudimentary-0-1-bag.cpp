#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1010;

int n, bv;
int v[N], w[N];
int f[N][N];

int main() {
    cin >> n >> bv;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        cin >> w[i];
    }

    // f[0][0 ~ m] = 0. Because no item is selected.
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= bv; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) {
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
            }
        }

    cout << f[n][bv] << endl;

    return 0;
}