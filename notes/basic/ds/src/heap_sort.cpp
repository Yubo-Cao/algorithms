#include <iostream>

using namespace std;

const int N = 1e6 + 10;

/**
 * Recursion based implementation to make it down. Notice this
 * is not necessary because log 1e19 approximately equal 64
 */
void down(int h[], int size, int u) {
    int t = u;
    if (u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (t != u) {
        swap(h[t], h[u]);
        down(h, size, t);
    }
}

/**
 * Loop based implementation to make it down.
 */
void while_down(int h[], int size, int u) {
    while (u * 2 <= size) {
        int t = u * 2;
        if (t + 1 <= size && h[t + 1] < h[t]) t++;
        if (h[t] >= h[u]) break;
        swap(h[t], h[u]);
        u = t;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int h[n + 1] = {0}, size = 0;
    for (int i = 1; i <= n; i++) cin >> h[i];
    size = n;
    for (int i = n / 2; i > 0; i--) while_down(h, size, i);

    while (m--) {
        cout << h[1] << " ";
        h[1] = h[size--];
        while_down(h, size, 1);
    }
    cout << endl;
    return 0;
}