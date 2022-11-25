#include <iostream>

using namespace std;

const int N = 1e3 + 10;

int n, m;
struct {
    int v;  // volume
    int w;  // value
    int s;  // at most choose
} items[N];
int f[N][N];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> items[i].v >> items[i].w >> items[i].s;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= items[i].s && k * items[i].v <= j; k++) {
                f[i][j] = max(f[i][j], f[i - 1][j - items[i].v * k] + items[i].w * k);
            }
        }
    }

    cout << f[n][m] << endl;
    return 0;
}