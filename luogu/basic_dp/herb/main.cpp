#include <cstring>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t, m;
    cin >> t >> m;
    int v[m], w[m];
    for (int i = 0; i < m; i++) cin >> w[i] >> v[i];

    int dp[t + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < m; i++)
        for (int j = t; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    cout << dp[t] << endl;

    return 0;
}