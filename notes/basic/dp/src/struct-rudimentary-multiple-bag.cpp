#include <cstring>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, v;
    cin >> n >> v;
    struct {
        int v, w, s;  // volume, weight, amount
    } a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i].v >> a[i].w >> a[i].s;

    int dp[n + 1][v + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= v; j++)
            for (int k = 0; k <= a[i].s && k * a[i].v <= j; k++)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * a[i].v] + k * a[i].w);
    cout << dp[n][v] << endl;

    return 0;
}