#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int find(int p[], int x) {  // return the root node for x, with path compression.
    if (p[x] != x) p[x] = find(p, p[x]);
    return p[x];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int p[n];
    for (int i = 0; i < n; i++) p[i] = i;

    while (m--) {
    }

    return 0;
}