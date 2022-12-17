#include <cstring>
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, v;
    cin >> n >> v;

    struct {
        int v;
        int w;
    } items[n + 1];

    for (int i = 1; i <= n; i++) cin >> items[i].v >> items[i].w;

    int dp[n + 1][v + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= v; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= items[i].v)
                dp[i][j] = max(dp[i][j],
                               dp[i - 1][j - items[i].v] + items[i].w);
        }
    }
    cout << dp[n][v] << endl;

    return 0;
}