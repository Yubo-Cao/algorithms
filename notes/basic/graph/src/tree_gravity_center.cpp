/**
 * Given a tree with n nodes that marked from 1 to n and n - 1 edges, find the
 * gravity center of the tree.
 *
 * Gravity center is defined as a node in tree, which its deletion will make the
 * number of nodes in each connected component of the tree as small as possible.
 *
 * Input format:
 * - The first line contains an integer n, which is the number of nodes in the
 *   tree.
 * - The second n - 1 line contains two integers a and b, which means there is
 *   an edge between node a and node b.
 *
 * Output format:
 * - Output an integer, which is the maximum number of nodes in each connected
 *  component of the tree after deleting the gravity center.
 */

#include <bitset>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Tree {
    int *h;   // head pointer to each linked list, for each elements
    int *ne;  // next pointer
    int *e;   // real elements
    int idx;  // internal pointer, point to next empty position in e
    int n;    // number of nodes

   private:
    int dfs_size(int k) {
        if (h[k] == -1) return 1;
        int size = 1;
        stack<int> s;
        s.push(k);
        while (!s.empty()) {
            int t = s.top();
            s.pop();
            for (int i = h[t]; i != -1; i = ne[i]) {
                size++;
                s.push(e[i]);
            }
        }
        return size;
    }

   public:
    Tree(int n) {
        h = new int[n];
        ne = new int[n << 1];
        e = new int[n << 1];
        idx = 0;
        this->n = n;
        memset(h, -1, sizeof(int) * n);
    }
    ~Tree() {
        delete h;
        delete ne;
        delete e;
    }

    void add(int a, int b) {
        e[idx] = b;
        ne[idx] = h[a];
        h[a] = idx++;
    }

    int size() {
        return dfs_size(0);
    }

    int size(int k) {
        return dfs_size(k);
    }

    void print() {
        // bfs print tree
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        int last_level = 0;
        while (!q.empty()) {
            pair<int, int> t = q.front();
            q.pop();
            if (t.second != last_level) {
                cout << endl;
                last_level = t.second;
            }
            cout << t.first << " ";
            for (int i = h[t.first]; i != -1; i = ne[i]) {
                q.push(make_pair(e[i], t.second + 1));
            }
        }
    }

    void raw_print() {
        // print array
        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            for (int j = h[i]; j != -1; j = ne[j]) {
                cout << e[j] << " ";
            }
            cout << endl;
        }
    }

    class iter {
        int *h;
        int *ne;
        int *e;
        int idx;
        int k;

       public:
        iter(int *h, int *ne, int *e, int k) {
            this->h = h;
            this->ne = ne;
            this->e = e;
            this->k = k;
            idx = h[k];
        }
        int next() {
            if (idx == -1) return -1;
            int t = e[idx];
            idx = ne[idx];
            return t;
        }
    };

    iter children(int k) {
        return iter(h, ne, e, k);
    }

    iter children() {
        return iter(h, ne, e, 0);
    }
};

int max_node_in_each_component(Tree &t, int k) {
    int m = 0;
    auto iter = t.children(k);
    int c;
    while ((c = iter.next()) != -1) {
        m = max(m, t.size(c));
    }
    return max(m, t.size() - t.size(k));
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    Tree tree(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree.add(a - 1, b - 1);
    }

    int min = n;
    for (int i = 0; i < n; i++) {
        int sz = max_node_in_each_component(tree, i);
        if (sz < min) min = sz;
    }
    cout << min << endl;
    return 0;
}