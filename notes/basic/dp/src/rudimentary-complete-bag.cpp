#include <iostream>

using namespace std;

const int N = 1e4 + 10;

struct {
    int v, w;
} items[N];
int n, m;
int f[N][N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> items[i].v >> items[i].w;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            for (int k = 1; k <= j / items[i].v; k++) {
                f[i][j] = max(f[i][j], f[i - 1][j - k * items[i].v] + k * items[i].w);
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}