#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    int a[n + 2][n + 2];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> a[i][j];
    int dp[n + 1][n + 1];
    memset(dp, 0x80, sizeof(dp)); // -INF, 0x80 = -128
    dp[1][1] = a[1][1];
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
    cout << *max_element(dp[n], dp[n] + n + 1) << endl;
    return 0;
}