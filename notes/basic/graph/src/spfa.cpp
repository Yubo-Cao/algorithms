#include <bitset>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5 + 10, M = 1e5 + 10, INF = 0x3f3f3f3f;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int dst[N];
bitset<N> st;

void add(int a, int b, int wt) {
    e[idx] = b;
    w[idx] = wt;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool spfa() {
    memset(dst, INF & 0xff, sizeof dst);
    dst[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while (!q.empty()) {
        int t = q.front();
        q.pop();

        st[t] = 0; // one may put it back again

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            int alt_dst = dst[t] + w[i];
            if (alt_dst < dst[j]) {
                dst[j] = alt_dst;
                if (!st[j]) q.push(j);
                st[j] = 1;
            }
        }
    }

    return dst[n] <= INF / 2;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    memset(h, -1, sizeof h);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w);
    }

    if (spfa())
        cout << dst[n];
    else
        cout << "impossible";
    cout << endl;
    return 0;
}
