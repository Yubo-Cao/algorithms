# Data Structure

## Linked List

- A head pointer is needed to point to the first node.
- Each node has two fields: `val` and `next`.
- The last node points to `NULL`.

![](linked-list.png)

### Struct-based Implementation

```cpp
struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};
```

In order to create a linked list, we need to create a `Node` first. Then we can create a linked list by connecting these `Node`s.

```cpp
Node* head = new Node(1);
head->next = new Node(2);
head->next->next = new Node(3);
```

The above implementation is usually not recommended. Because the creation of new objects is expensive. In practice, where `1e6-1e7` nodes are needed, we should use `new` as less as possible. Hence, array-based implementation is usually preferred.

### Array-based Singly Linked List

- Create 2 Array
  - The first array, `e[N]`, stores the value of each node.
  - The second array, `ne[N]`, stores the index of the next node. Specifically, `-1` means `NULL`.
- The node's identifier is the index of the node in the array. For example, the head node point to `ne[0]`with the value of`e`[0]`.

```cpp
class List {
    int head;   // index of the first element
    int e[N];   // value of the element
    int ne[N];  // index of the next element
    int idx;    // index of the next empty element

   public:
    List() {
        head = -1;
        idx = 0;
    }

    void prepend(int x) {
        e[idx] = x;
        ne[idx] = head;
        head = idx;
        idx++;
    }

    void insert(int k, int x) {
        e[idx] = x;
        ne[idx] = ne[k];
        ne[k] = idx;
        idx++;
    }

    void append(int x) {
        if (head == -1) {
            prepend(x);
            return;
        }
        int k = head;
        while (ne[k] != -1) k = ne[k];
        insert(k, x);
    }

    void remove(int k) {
        if (k == head) {
            head = ne[k];
            return;
        }
        ne[k] = ne[ne[k - 1]];
        // one may optimize this and reuse idx.
        // memory leak is ignored in algorithm questions.
    }

    void print() {
        for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
        cout << endl;
    }
};
```

### Array-based Doubly Linked List

- To improve the performance of a singly linked list, we can use a doubly linked list.
- In a doubly linked list, each node has two pointers: `prev` and `next`.
- In an array-based implementation, we will create 3 arrays: `e[N]`, `prev[N]`, and `next[N]`. For the sake of simplicity, let's say the head node is `0`.

<!-- TODO: Deal with code -->

```cpp
class List {
    int e[N];        // value of the element
    int l[N], r[N];  // the left and right pointer of the element
    int idx;         // index of the next empty element

   public:
    List() {
        // since head and tail take up two elements, we start from 2
        idx = 2;
        // head and tail are 0, 1
        r[0] = 1;
        l[1] = 0;
    }

    void insert(int k, int x) {
        e[idx] = x;
        r[idx] = r[k];
        l[idx] = k;
        l[r[k]] = idx;
        r[k] = idx;
    }

    void insert_left(int k, int x) { insert(l[k], x); }

    int remove(int k) {
        r[l[k]] = r[k];
        l[r[k]] = l[k];
        int result = e[k];
        e[k] = 0;
        return result;
    }

    void print() {
        for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
        cout << endl;
    }
};
```

## Stack & Queue

### Stack

- The stack is a LIFO (Last In First Out) data structure.

```cpp
int stk[N], tt;

void push(int x) { stk[++tt] = x; }
int pop() { return stk[tt--]; }
bool empty() { return tt == 0; }
int peek() { return stk[tt]; }
```

### Queue

- The queue is a FIFO (First In First Out) data structure.

```cpp
int q[N], hh, tt = -1;

void enqueue(int x) { q[++tt] = x; }
int dequeue() { return q[hh++]; }
bool empty() { return hh <= tt; }
int head() { return q[hh]; }
int tail() { return q[tt]; }
```

- The above implementation is not efficient. We can use a circular queue to improve performance. That is, reuse the space of the queue, rather than leaving empty spaces in front.

```cpp
int q[N], hh, tt = -1;

void enqueue(int x) {
    tt = (tt + 1) % N;
    q[tt] = x;
}

int dequeue() {
    int result = q[hh];
    hh = (hh + 1) % N;
    return result;
}

bool empty() { return hh == (tt + 1) % N; }
int head() { return q[hh]; }
int tail() { return q[tt]; }
```

## Monotonic Stack & Queue

Consider using stack and queue to emulate a rudimentary solution. Then, consider the constraints that are available for us to eliminate some elements in the stack or queue. If monotonicity is obtained, then we can use binary search, first, last, and all kinds of operations to speed up the process.

### Monotonic Stack

Given a sequence of numbers, we want to find the next number is the left or right that is larger or smaller than the current number. For now, let's assume we want to find the number on the left that is smaller than the current number.

- Rudimentary solution: $O(n^2)$

```cpp
for (int i = 0; i < n; i++) {
    int j = i + 1;
    while (j < n && a[j] <= a[i]) j++;
    if (j == n) cout << -1 << ' ';
    else cout << a[j] << ' ';
}
```

- Monotonic stack: $O(n)$
  - To find the next number that is smaller than the current number, we can use a stack to store all the numbers that were on the left of the current number. Then, we iterate through the stack (just, pop, pop, and pop) to find the next number that is smaller than the current number.
    - If the stack is empty, then no number is smaller than the current number.
    - Otherwise, the top of the stack is the next number that is smaller than the current number.
    - The reason that we can pop them, is because if `a[i] >= a[j]` and`i < j`, then `a[i]`must not be the closest smaller number, as the `[j]` that follows must be a more proper candidate.
  - Finally, put an `a[j]` into the stack for the next elements' comparison.

```cpp
#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int stk[N], tt;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (tt && stk[tt] >= x) tt--;
        if (tt)
            cout << stk[tt] << ' ';
        else
            cout << -1 << ' ';
        stk[++tt] = x;
    }

    return 0;
}
```

### Monotonic Queue

- Find the rolling max and min of a sequence of numbers (i.e., the max/min of a sliding window).

- Rudimentary solution: $O(nk)$

```cpp
int main() {
    int n, k;
    cin >> n >> k;
    int a[n];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i <= n - k; i++) {
        int res = -2e9;
        for (int j = i; j < i + k; j++) res = max(res, a[j]);
        cout << res << ' ';
    }
    return 0;
}
```

- If we use a monotonic queue, we can reduce the time complexity to $O(n)$.
  - Whenever a new element is added, we pop all the elements that are smaller than the new element.
  - Then, print out the first element of the queue, which is the max/min of the current window.

```cpp
#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int a[n] = {0};
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int q[n] = {0}, tt = -1, hh = 0;  // q stores the index of number in a
    for (int i = 0; i < n; i++) {
        if (hh <= tt && i - k + 1 > q[hh]) hh++;    // remove number last sliding window, if necessary
        while (hh <= tt && a[q[tt]] >= a[i]) tt--;  // ensure monotonicity. head is smallest
        q[++tt] = i;                                // put new number
        if (i >= k - 1) printf("%d ", a[q[hh]]);    // if enough number in here
    }
    puts("");
    tt = -1, hh = 0;
    for (int i = 0; i < n; i++) {
        if (hh <= tt && i - k + 1 > q[hh]) hh++;
        while (hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;
        if (i >= k - 1) printf("%d ", a[q[hh]]);
    }
    puts("");
    return 0;
}
```

## KMP

### Rudimentary Solution

- Brute force: $O(nm)$

```cpp
#include <iostream>

using namespace std;

bool isMatch(string s, string p) {
    int n = s.size(), m = p.size();
    for (int i = 0; i <= n - m; i++) { // enumerate all possible starting points
        bool match = true;
        for (int j = 0; j < m; j++) { // check if p matches s[i..i+m-1]
            if (s[i + j] != p[j]) {
                match = false;
                break;
            }
        }
        if (match) return true;
    }
    return false;
}

int main() {
    string s, p;
    cin >> s >> p;
    if (isMatch(s, p))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
```

![](rudimentary-kmp.png)

- In the above solution, a lot of repetitive matching happened. For example, when we are matching `s[1..3]` and `p[1..3]`, we have already matched `s[1..2]` and `p[1..2]`. We can use this information to speed up the process.

### KMP

- KMP: $O(n+m)$
  - We can use a `next` array to store the information of the longest prefix that is also a suffix of the current string.
    - if `next[i] = j` and the string is `s`, then `s[0..j-1] = s[i-j..i-1]`.
    - ![](kmp-next.png)
  - With this information, every time we fail to match a character, we can jump to the next possible position, rather than starting from the beginning.
    - ![](kmp.png)
    - In this figure, the match failed at `i` and `j + 1`. We will not reset the `j` to 0 and `i` to `i - j + 1`, but rather, we will set `j = next[j]`, and try again.
      - We are confident that `s[i - j  + 1 + k] = p[k]` for `k` in `[0, j - 1], because, by definition of the `next` array, this prefix and suffix are the same. We are also confident that we can't match anywhere before that, because if we can, then the prefix and suffix would be longer, which is a contradiction.
      - As `i` pointer is not moved, by resetting `j`, we merely moved the string `p` to the right, as we are still trying to match between `i - j + 1` and `i - j + m`.

```cpp
#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;

int n, m;
char p[N], s[M];
int ne[N];  // shadows std::next

int main() {
    cin >> n >> p + 1 >> m >> s + 1;

    // find next
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;
        ne[i] = j;
    }

    // match
    for (int i = 1, j = 0; i <= m; i++) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == n) {
            // success
            printf("%d ", i - n);
            j = ne[j];
        }
    }

    return 0;
}
```

- In the above nested-loop, `j` will always be minus by at least 1. As there is at most `m` addition to `j`, the time complexity is $O(n+m)$.

## Trie (Prefix Tree)

- Trie tree is used to store and search a set of strings. It supports the following operations:
  - `insert(s)`: insert a string `s` into the trie tree.
  - `count(s)`: count the number of strings in the trie tree that are prefixed by `s`.
  - `contains(s) == count(s) > 0`: check if the trie tree contains a string `s`.
  - `delete(s)`: delete a string `s` from the trie tree.

### Mechanism & Implementation

- Let's say we want to store `abc`, `anish`, `abcdef`, `bcdf`, and `cdef`.
  - There is some condition on those strings. The **alphabet must be limited**. For example, we only use lowercase letters, in the above example.
  - If a huge amount of characters are used, then one way to circumvent this is to convert the string into hexadecimal, rather than store them directly, creating large, sparse arrays.
- We then insert those strings into the trie tree.
  - ![](trie.png)
  - We start from the root and add a new node for each character in the string.
  - For example, when we insert `anish`, we first check if there is a node with label `a`. If not, we create one (which is the root node's child). Then we check if there is a node as a child of `a` with label `n`. If not, we create one. And so on. In the end, we mark this node so that we know that this is the end of a string, and `a`, `an`, won't be treated as inside the trie.
- We can also search for a string in the trie tree. To do that, we just walk down the tree and check if there is a node with the label of the next character in the string. If not, we know that the string is not in the trie tree. If we reach the end of the string, we check if the node is marked as the end of a string. If so, we know that the string is in the trie tree.
  - For example, `rnn` is not in the trie tree, because in the root node, there is no child with label `r`.
  - `ani` is not in the trie tree, because in the end, `i` node is not marked as the end of a string.

```cpp
#include <iostream>

using namespace std;

const int N = 1e5 + 10;  // N is the maximum number of nodes in the trie
const int M = 26;        // size of alphabet

int trie[N][M];  // trie[i][j] is the index of the node that is the child of node i and has the character j.
int cnt[N];      // cnt[i] is the number of words that end at node i
int idx;         // idx is the number of nodes in the trie. 0 is the root node and is empty

void insert(const char *s) {
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int u = s[i] - 'a';
        if (!trie[p][u]) trie[p][u] = ++idx;
        p = trie[p][u];
    }
    cnt[p]++;
}

int query(const char *s) {
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int u = s[i] - 'a';
        if (!trie[p][u]) return 0;
        p = trie[p][u];
    }
    return cnt[p];
}
```

## Union Find

A data structure that supports the following operations:

- `init(n)`: initialize the data structure with `n` elements.
- `merge(a, b)`: merge the set that contains `a` and the set that contains `b`.
- `find(a)`: find the set that contains `a`.
- `is_same(a, b)`: check if `a` and `b` are in the same set.

### Rudimentary Implementation

To support the above operations, we can use an array `p` to store the identifier of each element. The identifier of an element is the identifier of the set that contains this element.

```cpp
int p[N];

int is_same(int a, int b) {
    return p[a] == p[b];
}

int merge(int a, int b) {
    int x = find(a), y = find(b);
    if (x != y)
        for (int i = 0; i < n; i++)
            if (p[i] == x) p[i] = y;
}

int find(int x) {
    return p[x];
}
```

- The above implementation is not efficient. The time complexity of `find` and `is_same` is $O(1)$, and the time complexity of `merge` is $O(n)$.

### Use Union

- Union find can support both of those 2 operations, in almost the same time complexity (however, a bit worse than the above implementation).
  - **Each set is stored as a tree**
  - The identifier of elements is the identifier of the root of the set that contains this element.
  - There is an array `p` to store the parent of each element. The root of a set has `p[x] == x`. Therefore, to merge 2 sets, we just need to move 1 root node into another set as a child.
    - Notice that the time necessary to find the root node is $O(N)$ in the worst case. However, we can use **path compression** to reduce the time complexity to $O(1)$.
    - Every time we find a root node, we set the parent of this node to the root node of the set that contains this node.
    - One may also implement **union by** rank\*\* to reduce the time complexity. This requires us to maintain an array `r` to store the rank of each set. The rank of a set is the maximum depth of the tree. When we merge 2 sets, we always merge the set with a smaller rank into the set with a larger rank. This can reduce the time complexity of `merge` to $O(\log N)$. However, compared to **path compression**, this is not very useful——in practice, this is rarely used.

```cpp
#include <iostream>

using namespace std;

int find(int p[], int x)
{
    int r = x;
    while (p[r] != r)
        r = p[r];
    while (p[x] != x)
    {
        int y = p[x];
        p[x] = r;
        x = y;
    }
    return r;
}

int find_recursion(int p[], int x){
    if (p[x] == x) return x;
    else return p[x] = find_recursion(p, p[x]);
}

int main()
{
    int n, m;
    cin >> n >> m;

    int p[n];
    for (int i = 0; i <= n; i++)
        p[i] = i;

    while (m--)
    {
        char op;
        int a, b;
        cin >> op >> a >> b;

        switch (op)
        {
        case 'M':
            p[find(p, a)] = find(p, b);
            break;
        case 'Q':
            if (find(p, a) == find(p, b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            break;
        default:
            cout << "ERROR" << endl;
        }
    }

    return 0;
}
```

### Extended Implementation

Let's suppose we want to maintain the size of each set. We can use an array `s` to store the size of each set. The size of a set is the number of elements in this set. This can be done by adding some callback during the invocation of the `merge` function.

```cpp
#include <iostream>

using namespace std;

int find(int p[], int x) {
    int r = x;
    while (p[r] != r)
        r = p[r];
    while (p[x] != x) {
        int y = p[x];
        p[x] = r;
        x = y;
    }
    return r;
}

void merge(int p[], int s[], int a, int b) {
    int ra = find(p, a), rb = find(p, b);
    if (ra != rb) {
        p[ra] = rb;
        s[rb] += s[ra];
    }
}

int get_size(int p[], int s[], int a) {
    return s[find(p, a)];
}

bool in_same(int p[], int a, int b) {
    return find(p, a) == find(p, b);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int p[n + 1], s[n + 1];
    for (int i = 1; i <= n; i++)
        p[i] = i, s[i] = 1;

    while (m--) {
        string op;
        int a, b;
        cin >> op;
        if (op == "C") {
            cin >> a >> b;
            merge(p, s, a, b);
        } else if (op == "Q1") {
            cin >> a >> b;
            cout << (in_same(p, a, b) ? "Yes" : "No") << endl;
        } else if (op == "Q2") {
            cin >> a;
            cout << get_size(p, s, a) << endl;
        } else {
            cout << "ERROR" << endl;
            return -1;
        }
    }
    return 0;
}
```


- We can store additional information in the root node of each set. We may as well store the max, min, sum, etc. of the set in the root node. 
- In the above implementation, we use an array size `n + 1`, because the elements start from 1, and I am lazy to minus `1`.

## Heap

- A heap is a tree-like data structure that satisfies the heap property. The heap property is that the value of each node is greater than or equal to (in a max heap) or less than or equal to (in a min-heap) the values of its children, according to a comparison operator defined for the data structure. A heap is a useful data structure when it is necessary to repeatedly remove the object with the highest (or lowest) priority.
- A heap provides the following operations:
  - `insert`: insert a new element into the heap.
  - `delete`: delete the element with the highest (or lowest) priority.
  - `get`: get the element with the highest (or lowest) priority.
- Optionally, a heap may also support the following operations:
  - `change`: change the priority of an element.
  - `delete`: delete an arbitrary element.
  - Notice that the above 2 operations are not supported by STL's `priority_queue`.

### Mechanism

- Heap is a complete binary tree.
  - A complete binary tree is a binary tree in which every level, except possibly the last, is filled, and all nodes are as far left as possible.
  - ![](complete_binary_tree.png)
- It satisfies the heap property.
  - In a max heap, the value of each node is greater than or equal to the values of its children.
  - In a min heap, the value of each node is less than or equal to the values of its children.
  - Therefore, the root node is the element with the highest (or lowest) priority.
- All the heap is stored as an **1-d array**. You can think it as a when you store a complete binary tree layer-by-layer.
  - `a[1]` is the root
  - `a[2]` and `a[3]` are the children of `a[0]`. They are left and right children respectively.
  - `a[2x]` and `a[2x + 1]` are the children of `a[x]`. They are left and right children respectively.
  - The index of the parent node of `a[x]` is `x / 2`.

> The index may start from 0. However, this make the implementation more complicated. So I will use 1-based index.

### Primitive

All the API of the heap can be implemented as a composition of those primitive operations. For sake of simplicity, we will discuss only min heap.
- `down(int x)`: move the element at `a[x]` down to its correct position.
  - Exchange the node with its smallest child, as long as the node is greater than its smallest child until the node becomes a leaf node or the node is smaller than its smallest child.
- `up(int x)`: move the element at `a[x]` up to its correct position.
  - Exchange the node with its parent, as long as the node is smaller than its parent until the node becomes the root node or the node is greater than its parent.

```cpp
int heap[N];

void down(int x) {
    while ((x << 1) <= n) {
        int t = x << 1;
        if (t + 1 <= n && heap[t + 1] < heap[t]) t++;
        if (heap[x] <= heap[t]) break;
        swap(heap[x], heap[t]);
        x = t;
    }
}

void up(int x) {
    while (x > 1) {
        int t = x / 2;
        if (heap[t] <= heap[x]) break;
        swap(heap[t], heap[x]);
        x = t;
    }
}
```

### Implementation

- `insert`: insert a new element into the heap.
  - Add the element to the end of the heap.
  - Move the element up to its correct position (`up`).
- `min`: get the element with the highest (or lowest) priority.
  - Return `a[1]`.
- `delete`: delete the element with the lowest priority.
  - Exchange the root node with the last node, then remove the last node. We don't delete the head directly, because that's difficult and needs a lot of copy elements.
  - Move the new root node down to its correct position (`down`).
- `delete_any`: delete an arbitrary element.
  - To delete element `k`, simply set `heap[k] = heap[size]` and `size--`. If `heap[k] >= heap[size]`, then move `k` down to its correct position. Otherwise, move `k` up to its correct position (since `up`, `down` won't do anything if the direction is wrong, you may as well write `up(k)`, `down(k)` without checking the direction).
- `modify`: checking, or `down` and `up`.
- `init`: initialize the heap.
  - A rudimentary way is to insert all the elements one by one. However, this is inefficient $O(n \log n)$.
  - We first insert all the elements into the heap, regardless of the heap property. Then, we `heapify` it by `down` all the first half of the elements. This is $O(n)$.
    - This works, because if all the first half of the elements are in order, then the heap property is satisfied---those leaf nodes don't have any children, so they are already in order.
    - For all nodes in level `i`, it can at most be moved down for `k - i` times, where `k` is the height of the tree. Hence, the above time complexity can be calculated as 
    $$
    \begin{aligned}
    \frac{1}{2} \times 1 + \frac{1}{4} \times 2 + \frac{1}{8} \times 3 + \cdots + \frac{1}{2^k} \times k &= \frac{1}{2} \times \frac{1}{1 - \frac{1}{2^k}} \\
    &= \frac{1}{2} \frac{1}{1 - \frac{1}{2}} \\
    &= 1 \\ 
    &= \boxed{O(n)}
    \end{aligned}
    $$
    - One may, as well as prove it by saying that a heap is constructed whenever a new element is inserted. 

#### Priority Queue

```cpp
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

/**
 * Recursion based implementation to make it down.
 */
void down(int h[], int size, int u) {
    int t = u;
    if (u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (t != u) {
        swap(h[t], h[u]);
        down(h, size, t);
    }
}

/**
 * Loop based implementation to make it down.
 */
void while_down(int h[], int size, int u) {
    while (u * 2 <= size) {
        int t = u * 2;
        if (t + 1 <= size && h[t + 1] < h[t]) t++;
        if (h[t] >= h[u]) break;
        swap(h[t], h[u]);
        u = t;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int h[n + 1] = {0}, size = 0;
    for (int i = 1; i <= n; i++) cin >> h[i];
    size = n;
    for (int i = n / 2; i > 0; i--) while_down(h, size, i);

    while (m--) {
        cout << h[1] << " ";
        h[1] = h[size--];
        while_down(h, size, 1);
    }
    cout << endl;
    return 0;
}
```

#### Full Implementation

```cpp
#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Heap {
    int *h;    // storage of elements in heap
    int *ph;   // order of insertion -> index of element in heap
    int *hp;   // index of element in heap -> order of insertion
    int size;  // the size of the heap
    int m;     // m-th insertion

    void swap(int a, int b) {
        std::swap(ph[hp[a]], ph[hp[b]]);
        std::swap(hp[a], hp[b]);
        std::swap(h[a], h[b]);
    }

    void down(int u) {
        while (u * 2 <= size) {
            int t = u * 2;
            if (t + 1 <= size && h[t + 1] < h[t]) t++;
            if (h[t] >= h[u]) break;
            swap(t, u);
            u = t;
        }
    }

    void up(int u) {
        while (u / 2 && h[u / 2] > h[u]) {
            swap(u / 2, u);
            u /= 2;
        }
    }

   public:
    Heap(int n) {
        h = new int[n + 1];
        ph = new int[n + 1];
        hp = new int[n + 1];
        size = 0;
        m = 0;
    }
    ~Heap() {
        delete h;
        delete ph;
        delete hp;
    }

    void insert(int x) {
        size++, m++;
        ph[m] = size;
        hp[size] = m;
        h[size] = x;
        up(size);
    }
    int min() {
        return h[1];
    }
    void remove(int k) {
        swap(k, size);
        size--;
        down(k), up(k);
    }
    void remove_nth(int k) {
        remove(ph[k]);
    }
    void remove_min() {
        swap(1, size);
        size--;
        down(1);
    }
    void modify(int k, int x) {
        h[k] = x;
        down(k), up(k);
    }
    void modify_nth(int k, int x) {
        modify(ph[k], x);
    }
    void print() {
        int level = 1;
        for (int i = 1; i <= size; i++) {
            if (i == level) {
                cout << endl;
                level *= 2;
            }
            cout << h[i] << " ";
        }
        cout << endl;
        cout << min() << " " << size << endl;
    }
};

int main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    Heap h = Heap(n);

    string op;
    int k, x;
    while (n--) {
        cin >> op;
        if (op == "I") {
            cin >> x;
            h.insert(x);
        } else if (op == "PM") {
            cout << h.min() << endl;
        } else if (op == "DM") {
            h.remove_min();
        } else if (op == "D") {
            cin >> k;
            h.remove_nth(k);
        } else if (op == "C") {
            cin >> k >> x;
            h.modify_nth(k, x);
        } else {
            cout << "ERROR: Invalid command '" << op << "'" << endl;
            return -1;
        }
    }
    return 0;
}
```

## Hash Table

- Hashtable is a data structure that maps keys to values for highly efficient lookup.
  - Similar to discretization. We can map a large range of values to a small range of values.
  - We can also make some associations between keys and values.
- It provides a following functions:
  - `insert(key, value)`: insert a key-value pair into the hashtable.
  - `search(key)`: search the value corresponding to a key.
  - `contains(key)`: check if the key is in the hashtable.

### Hash Function

- A hash function is a function that can map a large range of values to a small range of values.
  - Hash function for integer can be mod operation.
    - We usually use the prime number that is as close as possible to the size of the hashtable, yet as far as possible from 2th power.
  - There is a probability that 2 different keys will be mapped to the same value. In such a situation, a **collision** occurs. Depending on the implementation, the collision may be resolved in different ways---separate chaining, open addressing, etc.

### Separate Chaining

- Separate chaining is a collision resolution method that uses a linked list to store the elements that have the same hash value.

![](separate_chaining.png)

- On average, we expect the length of the linked list to be `O(1)`. In the worst case, the length of the linked list can be `O(n)`. In such a situation, the time complexity of the hashtable is `O(n)`. Hence, the hashtable is not suitable for large data sets.
- Delete operation is rarely used in the hashtable. If we want to delete an element, we can simply mark it as deleted and not use it (i.e., making some boolean variable `true`).
  - If we must delete them physically, we can simply do the normal delete operation on the linked list.


```cpp





## STL
