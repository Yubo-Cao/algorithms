#include <iostream>

using namespace std;

// 1e3 items & 11 0-1 bag
const int N = 11010, M = 2010;

int n, m;
int v[N], w[N];
int f[N];

int main() {
    cin >> n >> m;

    int count = 0;
    for (int i = 1; i <= n; i++) {
        int a, b, s;
        cin >> a >> b >> s;

        int k = 1;
        while (k <= s) {
            v[++count] = a * k;
            w[count] = b * k;
            s -= k;
            k *= 2;
        }
        if (s > 0) {
            v[++count] = a * s;
            w[count] = b * s;
        }
    }

    n = count;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    cout << f[m] << endl;
    return 0;
}