# Graph and Search

## Depth-first Search (DFS)

- Given a tree. DFS starts from the root.
  - For each node, visit its children.
  - If a node has no children, go back to its parent.
    - If a node has no parent, go back to its grandparent.
    - And so on

![DFS](./figure/dfs.png)

### Properties

- It will always come down to the leaf node, as much as possible.
- Use a `stack` to implement. It will only remember all the nodes in the path, using $O(N)$ spaces. One may as well use recursion to implement DFS, which will use $O(N)$ spaces in the call stack, regardless.
- It may not find the shortest path to reach a node.


### Example

#### Permute Numbers

```cpp
#include <iostream>

using namespace std;

const int N = 10;

int n;
int path[N];
bool used[N];

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++) cout << path[i] << " ";
        cout << endl;
    }
    for (int i = 0; i < n; i++)
        if (!used[i]) {
            path[u] = i + 1;
            used[i] = true;
            dfs(u + 1);
            used[i] = false;
        }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> n;
    dfs(0);
    return 0;
}
```

- In the above code, we utilize the runtime stack to implement DFS.
- If we put a mapping after the `path` array, we can get the permutation of an arbitrary collection of numbers.

#### n-Queens

- Treat this as a permutation problem. Store 3-bit set, `col`, `dg` and `udg`, to record the status of each column, diagonal and anti-diagonal. Then we can use DFS to find all the solutions, that is, cut the possible children of the permutation tree dynamically in the DFS process, this is called **pruning**.

##### Column-wise DFS

- We are using `u + i` and `n - u + i` to store the status of the diagonal and anti-diagonal, respectively. This is because the y-intercept of the same diagonal is the same, and the y-intercept of the same anti-diagonal is the same --- $y = x + b$, then $b = y - x$. Plus `n` for the anti-diagonal, because the index of the array cannot be negative.

```cpp
#include <bitset>
#include <iostream>

using namespace std;

const int N = 9;

int n;
char q[N][N];
bitset<N> col;
bitset<2 * N> dg, udg;

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << q[i][j];
                if (j < n - 1) cout << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
            q[u][i] = 'q';
            col[i] = dg[u + i] = udg[n - u + i] = 1;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = 0;
            q[u][i] = '.';
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            q[i][j] = '.';
    dfs(0);
    return 0;
}
```

##### Element-wise DFS

```cpp
#include <bitset>
#include <iostream>

using namespace std;

const int N = 9;

int n;
char q[N][N];
bitset<N * 2> dg, udg;
bitset<N> col, row;

void dfs(int x, int y, int s) {
    if (s == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << q[i][j];
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int i = x; i < n; i++)
        for (int j = (i == x ? y : 0); j < n; j++)
            if (!row[i] && !col[j] && !dg[i + j] && !udg[n - i + j]) {
                q[i][j] = 'Q';
                row[i] = col[j] = dg[i + j] = udg[n - i + j] = 1;
                dfs(i, j + 1, s + 1);
                row[i] = col[j] = dg[i + j] = udg[n - i + j] = 0;
                q[i][j] = '.';
            }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            q[i][j] = '.';
    dfs(0, 0, 0);
    return 0;
}
```

## Breadth-first Search (BFS)

- First, create a queue, and put the root node into it.
  - Iterate the first element in the queue, and put its children into the queue.
  - Whenever we iterate a node, the node is removed from the queue.
- When the queue is empty, we have finished the BFS.

### Properties

- It will check each node, layer by layer.
- Use a `queue` to implement. It will remember each layer's nodes. Hence, using $O(2^h)$ spaces, where $h$ is the height of the tree.
- It will always find the **shortest** path to reach a node (if the graph is unweighted).


### Example

#### Maze

Walk through the maze from the start point at (0,0) to the endpoint at (n-1, m-1).


```cpp
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
```

## Depth-first & Breath-first Iteration

## Topological sort
