/**
 * Given an n×m two-dimensional integer array to represent a maze, the array
 * only contains 0 or 1, where 0 represents the path that can be walked, and 1
 * represents the wall that cannot be passed.
 *
 * Initially, a person is located at the upper left corner (1,1), and it is
 * known that the person can move one position in any direction up, down, left,
 * or right each time.
 *
 * How many times does the person need to move at least from the upper left
 * corner to the lower right corner (n,m).
 *
 * Input format:
 * - The first line contains two integers n and m (1≤n,m≤1000), indicating the
 *  size of the maze.
 * - The next n lines each contain m integers, representing the maze.
 *
 * Output format:
 * - Output a single integer indicating the minimum number of moves.
 */

#include <cstring>
#include <iostream>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e3 + 10;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int g[n][m];  // the maze, or the graph
    int d[n][m];  // the distance to the starting position
    memset(d, -1, sizeof d);
    d[0][0] = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    PII q[n * m];
    int hh = 0, tt = -1;
    q[++tt] = {0, 0};
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    while (hh <= tt) {
        auto t = q[hh++];
        for (int i = 0; i < 4; i++) {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m  // can walk
                && !g[x][y]                         // not wall
                && d[x][y] == -1                    // and haven't reached yet
            ) {
                d[x][y] = d[t.first][t.second] + 1;
                q[++tt] = {x, y};
            }
        }
    }

    cout << d[n - 1][m - 1] << endl;

    return 0;
}