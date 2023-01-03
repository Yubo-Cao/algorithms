#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int n, v;
    cin >> n >> v;

    struct
    {
        int v, w;
    } items[n + 1];

    for (int i = 1; i <= n; i++)
        cin >> items[i].v >> items[i].w;

    int dp[n + 1][v + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= v; j++)
        {
            dp[i][j] = dp[i - 1][j];
            for (int k = 1; k <= j / items[i].v; j++)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * items[i].v] + k * items[i].w);
        }
    }

    cout << dp[n][v] << endl;
}