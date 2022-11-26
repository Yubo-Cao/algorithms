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

Walk through the maze from the start point at (0,0) to the endpoint at (n-1, m-1). If one wants to store the path from the start point to the endpoint, we can use a `pre` array to store the previous node of each node. Then we can use the `pre` array to get the path.


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

## Storage

- The tree is a special graph, which has no cycle.
- Therefore, we shall store the tree in the same manner as the graph.
- An undirected graph is a special case of a directed graph. Hence, we can store the undirected graph in the same manner as the **directed graph**.


### Adjacency Matrix

- Store the graph in a $n \times n$ matrix.
- Usually not used in practice, because it is not space-efficient, especially for the sparse graph. Further, it does not support the storage of multiple edges.

```cpp
#include <iostream>

using namespace std;

int graph[10][10]; // number can be weight, or 0/1 indicate whether there is an edge

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        // there is an edge from a to b
        graph[a][b] = graph[b][a] = 1;
    }

    return 0;
}
```


### Adjacency List

- An array of linked lists' heads is called the **adjacency list**.

For example, the following graph

![](figure/graph.png)

can be stored as

```cpp
{
    1: 3 -> 4 -> NULL,
    2: 1 -> 4 -> NULL,
    3: 4 -> NULL,
    4 -> NULL
}
```

- The space complexity is $O(m)$, where $m$ is the number of edges. When we need to insert a new edge, we can do it in $O(1)$ time, by inserting at the head of the linked list. The expense is that we need to traverse the linked list to find the edge.

```cpp
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e6 + 10;
const int M = N * 2;

// 2 edges. hence, N * 2 elements in the linked list
int h[N], e[M], ne[M], idx;  // one may use vector to store as well. However, that's slow.

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void add_undirection(int a, int b) {
    add(a, b);
    add(b, a);
}

void remove(int a, int b) {
    int i = h[a];
    while (i != -1) {
        if (e[i] == b) {
            ne[i] = ne[ne[i]];
            break;
        }
        i = ne[i];
    }
}

void remove_undirection(int a, int b) {
    remove(a, b);
    remove(b, a);
}

int main() {
    // necessary init
    memset(h, -1, sizeof h);
    return 0;
}
```

## Depth-first & Breath-first Iteration

### Depth-first Iteration

- It will iterate as many children as possible and then go back to the parent node. In each iteration, it will mark a node as visited, because, in the graph, there may be cycles.

```cpp
bool seen[N];

// memset(seen, 0, sizeof seen); (don't forgot!)
void dfs(int u) {
    seen[u] = true;
    for (int i = h[u]; i != -1; i = ne[i]) {  // iterate all the neighbors of u
        int j = e[i];
        if (!seen[j]) {  // if the neighbor is not visited
            dfs(j);      // visit it
        }
    }
}
```

### Breath-first Iteration

- It will iterate the nodes layer by layer. In each iteration, it will mark a node as visited, because, in the graph, there may be cycles.

```cpp
bool seen[N];

void bfs(int u) {
    memset(seen, 0, sizeof seen);
    queue<int> q;  // queue to store the nodes to be visited
    q.push(u);     // push the starting node
    seen[u] = true;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i]) {  // iterate all the neighbors of t
            int j = e[i];
            if (!seen[j]) {
                q.push(j);
                seen[j] = true;
            }
        }
    }
}
```

### Example

#### The gravity center of a tree

```cpp
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;
const int M = N << 1;

int n;
int h[N], e[M], ne[M], idx;
bool st[N];

int ans = N;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

// the number of nodes in the u as a root
int dfs(int u) {
    st[u] = true;

    int sum = 1, res = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }

    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}

// IO
int main() {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    dfs(1);
    cout << ans << endl;
    return 0;
}
```

#### Topological sort

- This is for a directed acyclic graph (DAG). It is a linear ordering of vertices such that for every directed edge `u -> v`, `u` comes before `v` in the ordering.
  - If there is a cycle, then there is no topological sort. You just can't expand it in a linear order.
- Start from a node that has no incoming edges, i.e., **in-degree** is 0. Move all that kinds of nodes into a queue. Then, BFS the graph, using the previous queue as the starting point. For each:
  - Remove the edge from the current node to its neighbor.
  - If the neighbor has no incoming edges, i.e., **in-degree** is 0, then add it to the queue.
- If there is a cycle, then the queue will be empty before all the edges are removed (in below, `tt != n - 1`).

```cpp
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n, m;
int h[N], e[N], ne[N], idx;
int q[N], d[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
    d[b]++;
}

bool topsort() {
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
        if (!d[i]) q[++tt] = i;

    while (hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            d[j]--;
            if (!d[j]) q[++tt] = j;
        }
    }

    return tt == n - 1;  // all the points goes into the queue
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    memset(h, -1, sizeof h);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    if (topsort())
        for (int i = 0; i < n; i++) cout << q[i] << " ";
    else
        cout << -1;
    cout << endl;

    return 0;
}
```