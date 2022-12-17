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
    } is[n + 1];
    for (int i = 1; i <= n; i++) cin >> is[i].v >> is[i].w;

    int dp[n + 1][v + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= v; j++) {
            int m = dp[i - 1][j];
            for (int k = 0; k * is[i].v <= j; k++)
                m = max(m, dp[i - 1][j - k * is[i].v] + k * is[i].w);
            dp[i][j] = m;
        }
    }
    cout << dp[n][v] << endl;

    return 0;
}