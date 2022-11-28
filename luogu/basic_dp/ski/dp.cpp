#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int a[n][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    // sort the points by height. necessary because dp won't work
    // unless all points with lower height, which necessarily have
    // a lower path length, are already calculated.
    pair<int, pair<int, int> > points[n * m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            points[i * m + j] = {a[i][j], {i, j}};
    sort(points, points + n * m);

    int dp[n][m];
    // initialize dp array. each point has a path length of 1
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dp[i][j] = 1;

    // now, for each point, check if it can reach any of its
    // neighbors. if it can, then the path length is the maximum
    // of the path lengths of the neighbors plus 1.
    for (int i = 0; i < n * m; i++) {
        int x = points[i].second.first, y = points[i].second.second, h = points[i].first;
        int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j], ny = y + dy[j], nh = a[nx][ny];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nh >= h)
                continue;
            dp[x][y] = max(dp[x][y], dp[nx][ny] + 1);
        }
    }

    // find the longest path
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = max(ans, dp[i][j]);
    cout << ans << endl;

    return 0;
}