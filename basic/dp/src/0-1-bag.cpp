#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1010;

int n, bv;
int v[N], w[N];
int f[N];

int main() {
    cin >> n >> bv;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        cin >> w[i];
    }

    for (int i = 1; i <= n; i++)
        for (int j = bv; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[bv] << endl;

    return 0;
}