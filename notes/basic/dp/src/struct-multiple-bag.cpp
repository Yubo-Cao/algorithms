#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, v;
    cin >> n >> v;

    vector<pair<int, int>> a;
    while (n--) {
        int v, w, s;
        cin >> v >> w >> s;
        for (int k = 1; k <= s; k <<= 1)
            a.push_back({v * k, w * k}), s -= k;
        if (s > 0) a.push_back({v * s, w * s});
    }

    int dp[v + 1];
    memset(dp, 0, sizeof(dp));
    for (auto [vi, wi] : a)
        for (int j = v; j >= vi; j--)
            dp[j] = max(dp[j], dp[j - vi] + wi);
    cout << dp[v] << endl;

    return 0;
}