#include <iostream>

using namespace std;

int find(int p[], int x) {
    int r = x;
    while (p[r] != r)
        r = p[r];
    while (p[x] != x) {
        int y = p[x];
        p[x] = r;
        x = y;
    }
    return r;
}

void merge(int p[], int s[], int a, int b) {
    int ra = find(p, a), rb = find(p, b);
    if (ra != rb) {
        p[ra] = rb;
        s[rb] += s[ra];
    }
}

int get_size(int p[], int s[], int a) {
    return s[find(p, a)];
}

bool in_same(int p[], int a, int b) {
    return find(p, a) == find(p, b);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int p[n + 1], s[n + 1];
    for (int i = 1; i <= n; i++)
        p[i] = i, s[i] = 1;

    while (m--) {
        string op;
        int a, b;
        cin >> op;
        if (op == "C") {
            cin >> a >> b;
            merge(p, s, a, b);
        } else if (op == "Q1") {
            cin >> a >> b;
            cout << (in_same(p, a, b) ? "Yes" : "No") << endl;
        } else if (op == "Q2") {
            cin >> a;
            cout << get_size(p, s, a) << endl;
        } else {
            cout << "ERROR" << endl;
            return -1;
        }
    }
    return 0;
}