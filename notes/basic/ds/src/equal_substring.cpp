#include <algorithm>
#include <iostream>

using namespace std;

typedef unsigned long long ULL;

const int N = 1e6 + 10;
const int P = 131;

ULL pow_cache[N];

ULL pow(ULL b) {
    if (pow_cache[b]) return pow_cache[b];

    ULL result = 1, p = P, n = b;
    while(n) {
        if (n & 1) result *= p;
        p *= p;
        n >>= 1;
    }
    return pow_cache[b] = result;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    ULL h[n + 1] = {0};
    for (int i = 1; i <= n; i++) {
        // don't forgot -1
        h[i] = h[i - 1] * P + (s[i - 1] - '0' + 1);
    }

    while (m--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        // inclusive for l1, l2.
        ULL h1 = h[r1] - h[l1 - 1] * pow(r1 - l1 + 1),
            h2 = h[r2] - h[l2 - 1] * pow(r2 - l2 + 1);

        cout << ((h1 == h2) ? "Yes" : "No") << endl;
    }
    return 0;
}