#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 510;
const int INF = 0x3f3f3f3f;

int n, m;
int h[N], e[N], ne[N], w[N], idx;
bool st[N];
int dst[N];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int djikstra() {
    memset(dst, INF & 0xff, sizeof dst);
    dst[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> p;
    p.push({0, 1});

    while (!p.empty()) {
        auto t = p.top();
        p.pop();

        int d = t.first, i = t.second;
        if (st[i]) continue;  // already been processed. duplication in queue
        for (int j = h[i]; j != -1; j = ne[j]) {
            int k = e[j];
            if (dst[k] > d + w[j]) {
                dst[k] = d + w[j];
                p.push({dst[k], k});
            }
        }

        st[i] = true;
    }

    if (dst[n] == INF) return -1;
    return dst[n];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);  // duplicated elements don't need to be handled, because
        // the adjacent list.
    }

    cout << djikstra() << endl;
    return 0;
}