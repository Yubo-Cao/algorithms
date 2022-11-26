#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e6 + 10;
const int M = N * 2;

// 2 edges. hence, N * 2 elements in the linked list
int h[N], e[M], ne[M], idx;  // one may use vector to store as well. However, that's slow.

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void add_undirection(int a, int b) {
    add(a, b);
    add(b, a);
}

void remove(int a, int b) {
    int i = h[a];
    while (i != -1) {
        if (e[i] == b) {
            ne[i] = ne[ne[i]];
            break;
        }
        i = ne[i];
    }
}

void remove_undirection(int a, int b) {
    remove(a, b);
    remove(b, a);
}

// iterate
bool seen[N];

void dfs(int u) {
    memset(seen, 0, sizeof seen);
    seen[u] = true;
    for (int i = h[u]; i != -1; i = ne[i]) {  // iterate all the neighbors of u
        int j = e[i];
        if (!seen[j]) {  // if the neighbor is not visited
            dfs(j);      // visit it
        }
    }
}

void bfs(int u) {
    memset(seen, 0, sizeof seen);
    queue<int> q;  // queue to store the nodes to be visited
    q.push(u);     // push the starting node
    seen[u] = true;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i]) {  // iterate all the neighbors of t
            int j = e[i];
            if (!seen[j]) {
                q.push(j);
                seen[j] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    memset(h, -1, sizeof h);
    return 0;
}