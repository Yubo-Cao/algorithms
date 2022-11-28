#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;

    int a[n], f[n], ne[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        f[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && f[j] + 1 > f[i]) {
                f[i] = f[j] + 1;
                ne[i] = j;
            }
        }
    }

    int m = f[0], idx = 0;
    for (int i = 1; i < n; i++) {
        if (f[i] > m) {
            m = f[i];
            idx = i;
        }
    }

    cout << m << endl;
    stack<int> s;
    for (int i = 0; i < m; i++) {
        s.push(a[idx]);
        idx = ne[idx];
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    return 0;
}