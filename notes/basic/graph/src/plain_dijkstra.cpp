#include <cstring>
#include <iostream>

using namespace std;

const int N = 510;
const int INF = 0x3f3f3f3f;
int n, m;
int g[N][N];  // dense, use adj mat
int dst[N];
bool st[N];

int dijkstra() {
    memset(dst, INF & 0xff, sizeof dst);
    dst[1] = 0;

    for (int i = 0; i < n; i++) {
        // find min distance node
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dst[t] > dst[j]))
                t = j;
        st[t] = true;

        // update the distance
        for (int j = 1; j <= n; j++)
            dst[j] = min(dst[j], dst[t] + g[t][j]);
    }

    if (dst[n] == INF) return -1;
    return dst[n];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m;
    memset(g, INF & 0xff, sizeof g);  // init all to infinity

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    cout << dijkstra() << endl;
    return 0;
}