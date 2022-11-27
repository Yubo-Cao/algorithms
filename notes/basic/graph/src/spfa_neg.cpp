#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;

int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dst[N], cnt[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b,
    w[idx] = c,
    ne[idx] = h[a],
    h[a] = idx++;
}

int spfa() {
    queue<int> q;
    // notice we didn't memset dst to INF, because if there is a negative cycle,
    // dst will be updated regardless.

    // all the node can be the start point
    for (int i = 1; i <= n; i++) {
        q.push(i);
        st[i] = true;
    }

    // then, bfs
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dst[j] > dst[t] + w[i]) {
                dst[j] = dst[t] + w[i];
                // by pigeonhole principle, if cnt[j] > n, there must be a
                // negative cycle
                if ((cnt[j] = cnt[t] + 1) >= n) return true;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    memset(h, -1, sizeof h);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    if (spfa()) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}