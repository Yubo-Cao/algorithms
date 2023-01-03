#include <cstring>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, v;
    cin >> n >> v;

    struct {
        int w;
        int v;
    } items[n];
    for (int i = 0; i < n; i++) cin >> items[i].v >> items[i].w;

    int dp[v];
    memset(dp, 0, sizeof dp);

    for (int i = 0; i < n; i++)
        for (int j = v - 1; j >= items[i].v - 1; j--)
            dp[j] = max(dp[j], (j - items[i].v > 0)
                                   ? dp[j - items[i].v] + items[i].w
                                   : 0);

    cout << dp[v - 1] << endl;

    return 0;
}