#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int h[N], ph[N], hp[N], sz, m;

void heap_swap(int a, int b) {
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u) {
    while (u * 2 <= sz) {
        int t = u * 2;
        if (t + 1 <= sz && h[t + 1] < h[t]) t++;
        if (h[t] >= h[u]) break;
        heap_swap(t, u);
        u = t;
    }
}

void up(int u) {
    while (u / 2 && h[u / 2] > h[u]) {
        heap_swap(u / 2, u);
        u /= 2;
    }
}

void insert(int x) {
    sz++, m++;
    ph[m] = sz;
    hp[sz] = m;
    h[sz] = x;
    up(sz);
}

void remove(int x) {
    x = ph[x];
    heap_swap(x, sz--);
    down(x);
    up(x);
}

void remove_min() {
    heap_swap(1, sz--);
    down(1);
}

void modify(int k, int x) {
    k = ph[k];
    h[k] = x;
    down(k);
    up(k);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    string cmd;
    int x, k;
    while (n--) {
        cin >> cmd;
        if (cmd == "I") {
            cin >> x;
            insert(x);
        } else if (cmd == "PM") {
            cout << h[1] << endl;
        } else if (cmd == "DM") {
            remove_min();
        } else if (cmd == "D") {
            cin >> k;
            remove(k);
        } else if (cmd == "C") {
            cin >> k >> x;
            modify(k, x);
        }
    }

    return 0;
}