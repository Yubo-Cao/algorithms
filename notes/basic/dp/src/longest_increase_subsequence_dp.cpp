#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;

    int a[n], f[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        f[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && f[j] + 1 > f[i]) {
                f[i] = f[j] + 1;
            }
        }
    }

    int m = f[0];
    for (int i = 1; i < n; i++) {
        if (f[i] > m) {
            m = f[i];
        }
    }
    cout << m << endl;
    return 0;
}