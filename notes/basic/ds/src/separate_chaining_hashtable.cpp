#include <cstring>
#include <iostream>

using namespace std;

const int N = 100003;
int h[N], e[N], ne[N], idx;

int ha(int x) {
    return (x % N + N) % N;  // in C++, the mod of a negative number is negative. e.g., -10 % 3 = -1
}

void insert(int x) {
    // hash function
    int k = ha(x);
    e[idx] = x, ne[idx] = h[k], h[k] = idx++;
}

bool find(int x) {
    int k = ha(x);
    for (int i = h[k]; i != -1; i = ne[i])
        if (e[i] == x) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    memset(h, -1, sizeof h);

    int n; cin >> n;
    string op; int x;
    while (n--) {
        cin >> op >> x;
        if (op == "I") insert(x);
        else cout << (find(x) ? "Yes" : "No") << endl;
    }
    return 0;
}