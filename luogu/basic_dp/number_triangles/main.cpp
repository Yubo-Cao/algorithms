#include <iostream>

using namespace std;

const int INF = 1e9 + 1;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;

    int a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> a[i][j];

    int dp[n][n + 1];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i + 2; j++)
            dp[i][j] = -INF;

    dp[0][0] = a[0][0];
    for (int i = 1; i < n; i++)
        for (int j = 0; j <= i; j++) {
            dp[i][j] = dp[i - 1][j] + a[i][j];
            if (j > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i][j]);
        }

    int m = dp[n - 1][0];
    for (int i = 1; i < n; i++) m = max(m, dp[n - 1][i]);
    cout << m << endl;
    return 0;
}