/**
 * Given a directed graph with n points and m edges, there may be multiple edges
 * and self-loops in the graph, and the edge weight may be negative.
 *
 * Please find the shortest distance from point 1 to point n passing through at
 * most k edges. If it is impossible to go from point 1 to point n, output
 * impossible.
 *
 * Note: There may be negative weight loops in the graph.
 *
 * Input format:
 * - The first line contains three integers n,m,k.
 * - The next m lines, each line contains three integers x, y, z, indicating
 *   that there is a directed edge from point x to point y, and the edge length
 *   is z. The points are numbered from 1∼n.
 *
 * Output format:
 * - Output an integer representing the shortest distance from point 1 to point
 *   n passing through at most k edges. If there is no path that satisfies the
 *   condition, output impossible.
 */

#include <cstring>
#include <iostream>

using namespace std;

const int N = 510, M = 10010, INF = 0x3f3f3f3f;

int n, m, k;
int dst[N], backup[N];

struct Edge {
    int a;
    int b;
    int w;
} edges[M];

bool bellman_ford() {
    memset(dst, INF & 0xff, sizeof dst);
    dst[1] = 0;

    for (int i = 0; i < k; i++) {
        memcpy(backup, dst, sizeof dst);
        /* because of limitation of k, there is a chance that a successive edges
           will be iterated, and more than k node's path which is shortest got
           selected. Hence, only use the result from previous step */
        for (int j = 0; j < m; j++) {
            Edge e = edges[j];
            int a = e.a, b = e.b, w = e.w;
            dst[b] = min(dst[b], backup[a] + w);
        }
    }

    return dst[n] <= INF / 2;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    if (!bellman_ford())
        cout << "impossible";
    else
        cout << dst[n];
    cout << endl;
    return 0;
}