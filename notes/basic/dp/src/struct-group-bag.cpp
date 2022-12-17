#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, v;
    cin >> n >> v;
    struct Item {
        int v, w;
    };
    vector<vector<Item>> items(n + 1);
    items.push_back({{0, 0}});
    for (int i = 1; i <= n; i++) {
        int n;
        cin >> n;
        while (n--) {
            int v, w;
            cin >> v >> w;
            items[i].push_back({v, w});
        }
    }
    int dp[v + 1];
    memset(dp, 0, sizeof(dp));
    for (auto group : items)
        for (int j = v; j >= 0; j--)
            for (auto item : group)
                if (j >= item.v)
                    dp[j] = max(dp[j], dp[j - item.v] + item.w);
    cout << dp[v] << endl;

    return 0;
}