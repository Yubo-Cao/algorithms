#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100;
int n, m;
int a[N][N],  // height of each point
    c[N][N];  // cache for dfs

int dfs(int x, int y) {
    if (c[x][y]) return c[x][y];
    int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
    int ans = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i], nh = a[nx][ny];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || nh >= a[x][y])
            continue;
        ans = max(ans, dfs(nx, ny) + 1);
    }
    return c[x][y] = ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = max(ans, dfs(i, j));
    cout << ans << endl;

    return 0;
}