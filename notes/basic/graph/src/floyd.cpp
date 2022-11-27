#include <cstring>
#include <iostream>

using namespace std;

const int N = 210;
const int INF = 0x3f3f3f3f;

int n, m, qs;
int d[N][N];

void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m >> qs;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i == j)
                d[i][j] = 0;  // self-loop, then 0.
            else
                d[i][j] = INF;
        }

    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;

        d[a][b] = min(d[a][b], w);
    }

    floyd();

    while (qs--) {
        int a, b;
        cin >> a >> b;
        if (d[a][b] >= INF / 2) {
            cout << "impossible" << endl;
            continue;
        }
        cout << d[a][b] << endl;
    }

    return 0;
}