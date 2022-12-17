#include <cstring>
#include <iostream>

using namespace std;

int main() {
    int n, v;
    cin >> n >> v;

    struct
    {
        int w;
        int v;
    } items[n + 1];

    for (int i = 1; i <= n; i++)
        cin >> items[i].v >> items[i].w;

    int dp[n + 1][v + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= v; j++)
            dp[i][j] = max(dp[i - 1][j], (j >= items[i].v)
                                             ? dp[i][j - items[i].v] + items[i].w
                                             : 0);

    cout << dp[n][v] << endl;
}