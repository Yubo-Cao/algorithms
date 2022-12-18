#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

void print(int a[], int prev[], int i) {
    if (i == 0) return;
    print(a, prev, prev[i]);
    cout << a[i] << " ";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    int a[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int dp[n + 1], prev[n + 1];
    memset(prev, 0, sizeof(prev));

    for (int i = 1; i <= n; i++) dp[i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (a[i] > a[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
    int i = max_element(dp + 1, dp + n + 1) - dp;
    cout << dp[i] << endl;
    print(a, prev, i), cout << endl;
    return 0;
}
