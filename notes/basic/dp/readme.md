# Dynamic Programming

## Bag

Given $n$ items with size $A_i$ and value $V_i$, put these items into a bag of size $m$. What's the maximum value can you put into the bag?

### 0-1 Bag

Each item can only be used once.

- Define state as a property of a collection.
  - Collection $A_{i, j}$ means all the possible choices one can make, which only select at most $i$ items with a total volume of $j$.
  - Then, the state $f(A_{i, j})$ would be the maximum value of the collection $A_{i, j}$.
- To calculate the state, we need recursion.
  - $f(A_{i, j}) = \max\{f(A_{i - 1, j}), f(A_{i - 1, j - A_i}) + V_i\}$
    - That is, we either choose the item $i$ or not.
  - This is called **state transition**. It is the core of dynamic programming. It turns out to be the case of separating the problem into sub-problems.

#### Rudimentary

```cpp
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1010;

int n, bv;
int v[N], w[N];
int f[N][N];

int main() {
    cin >> n >> bv;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        cin >> w[i];
    }

    // f[0][0 ~ m] = 0. Because no item is selected.
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= bv; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) {
                // maybe j - v[i] < 0, then, it doesn't exists such a state.
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
            }
        }

    cout << f[n][bv] << endl;

    return 0;
}
```

- And the above is a rudimentary implementation of the 0-1 bag problem, using 2d arrays.

#### Optimization

- We notice, in the calculation of the next state:
  - We only need the previous state.
- Hence, we may eliminate the first dimension of the array. That is, we only need to maintain the previous state, and later operations will overwrite it. This is called a **rolling array**.

```cpp
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1010;

int n, bv;
int v[N], w[N];
int f[N];

int main() {
    cin >> n >> bv;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        cin >> w[i];
    }

    for (int i = 1; i <= n; i++)
        for (int j = bv; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]); // notice the order of the loop. This is necessary to achieve f[i - 1][j - v[i]], rather than f[i][j - v[i]];
    cout << f[bv] << endl;

    return 0;
}
```

### Complete Bag

Each item can be used unlimited times.

$$
f[i][j] = \max\{f[i - 1][j], f[i - 1][j - v_i] + w_i, f[i - 1][j - 2v_i] + 2w_i, \cdots, f[i - 1][j - kv_i] + kw_i\}
$$

- Basically, for each item, we can choose $0, 1, 2, \cdots, k$ times.
- The $k = \lfloor \frac{j}{v_i} \rfloor$.


#### Rudimentary

```cpp
#include <iostream>

using namespace std;

const int N = 1e4 + 10;

struct {
    int v, w;
} items[N];
int n, m;
int f[N][N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> items[i].v >> items[i].w;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            for (int k = 1; k <= j / items[i].v; k++) {
                f[i][j] = max(f[i][j], f[i - 1][j - k * items[i].v] + k * items[i].w);
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
```

#### Optimization

- First, the state transition is over-complicated:

$$
\begin{aligned}
f[i][j] &= \max\{f[i - 1][j], &f[i - 1][j - v_i] + w_i, &f[i - 1][j - 2v_i] + 2w_i, \cdots, f[i - 1][j - kv_i] + kw_i\} \\
f[i][j - v_i] &= \max\{&f[i - 1][j - v_i], &f[i - 1][j - 2v_i] + w_i, f[i - 1][j - 3v_i] + 2w_i, \cdots, f[i - 1][j - (k + 1)v_i] + kw_i\} \\
\end{aligned}
$$

- Therefore, $f[i][j] = \max\{f[i][j - v_i] + w_i, f[i - 1][j] + w_i\}$.

```cpp
for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
        f[i][j] = f[i - 1][j];
        if (j >= v[i]) f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
    }
}
```

- Similarly, we can use a rolling array.

```cpp
#include <iostream>

using namespace std;

const int N = 1e4 + 10;

int n, m;
int v[N], w[N];
int f[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++) {
        for (int j = v[i]; j <= m; j++) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[m] << endl;
    return 0;
}
```

### Multiple Bag

The constraint of each item is $k_i$, i.e., a different number of items can be used.

#### Rudimentary Implementation

```cpp
#include <iostream>

using namespace std;

const int N = 1e3 + 10;

int n, m;
struct {
    int v;  // volume
    int w;  // value
    int s;  // at most choose
} items[N];
int f[N][N];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> items[i].v >> items[i].w >> items[i].s;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= items[i].s && k * items[i].v <= j; k++) {
                f[i][j] = max(f[i][j], f[i - 1][j - items[i].v * k] + items[i].w * k);
            }
        }
    }

    cout << f[n][m] << endl;
    return 0;
}
```

The runtime is $O(nm^2)$.


#### Optimization

##### Complete bag

One might as well, expand the state transition:

$$
\begin{aligned}
f[i][j] &= \max\{f[i - 1][j], f[i - 1][j - v_i] + w_i, f[i - 1][j - 2v_i] + 2w_i, \cdots, f[i - 1][j - sv_i] + sw_i\} \\
f[i][j - v_i] &= \max\{f[i - 1][j - v_i], f[i - 1][j - 2v_i] + w_i, f[i - 1][j - 3v_i] + 2w_i, \cdots, \boxed{f[i - 1][j - (s + 1)v_i] + sw_i}\} \\
\end{aligned}
$$

- Unfortunately, the last term is here. Nor is it possible for us to find the max without the last term, given $f[i][j - v_i]$, because $\max$ simply eliminates that useful information.

##### Binary optimization

- For an arbitrary number $k$, we can split it into a finite sum of powers of $2$, and some remainder.
- For example, $k = 200$, then $k = 2^6 + 2^5 + 2^4 + 2^3 + 2^2 + 2^1 + 2^0 + 73$. The point is, now we can represent any number that's smaller than $200$ as 8 bits, where each bit represents whether we use that item or not.
  - For example, $1$ is simply `0000 0010`, which means we use the second to last term.
  - $128$ is `01101111`, as a summation of $2^5 + 2^4 + 2^2 + 2^1 + 2^0 + 73$ 
- This splits the number into $\log_2 k$ bits. The problem is then converted to a bunch of 0-1 bag problem. Now, the runtime is $O(nm\log_2 m)$.

```cpp
#include <iostream>

using namespace std;

// 1e3 items & 11 0-1 bag
const int N = 11010, M = 2010;

int n, m;
int v[N], w[N];
int f[N];

int main() {
    cin >> n >> m;

    int count = 0;
    for (int i = 1; i <= n; i++) {
        int a, b, s;
        cin >> a >> b >> s;

        int k = 1;
        while (k <= s) {
            v[++count] = a * k;
            w[count] = b * k;
            s -= k;
            k *= 2;
        }
        if (s > 0) {
            v[++count] = a * s;
            w[count] = b * s;
        }
    }

    n = count;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    cout << f[m] << endl;
    return 0;
}
```


### Group Bag

Some items are grouped, and only items from certain groups can be used (i.e., items from different groups may conflict).

```cpp
#include <iostream>

using namespace std;

const int N = 1e2 + 10;
int v[N][N], w[N][N], s[N];
int f[N];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 0; j < s[i]; j++) {
            cin >> v[i][j] >> w[i][j];
        }
    }

    for (int i = 1; i <= n; i++) { // the volume to be filled
        for (int j = m; j >= 0; j--) { // check for each group
            for (int k = 0; k < s[i]; k++) { // check for each item in the group
                if (v[i][k] <= j) {
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
                }
            }
        }
    }

    cout << f[m] << endl;
    return 0;
}
```

## Linear DP

If the path in which the state transition occurs is linear, then the state transition can be optimized. For example, in the bag problem, we update the volume from small to large/large to small. If there is an approximately linear relationship, we classify it as a linear DP problem.

### Numeric Triangle

- The state:
  - `f[i][j]`, representing the maximum sum of the path from the top to the $(i, j)$ point, out of all the path possible to move from the $(0,0)$ to $(i,j)$
  - The state may separated from choosing left or choosing right in the previous step. 
    - Then the current state can be deduced as `max(f[i - 1][j - 1] + w[i][j], f[i - 1][j] + w[i][j])` 
    > For the sake of simplicity, one may read the numbers in starting from 1. This prevent i >= 1 that kind of check.

- The time complexity is usually the number of states, times the time complexity of transition. Hence, this algorithm takes $O(N^2)$ times.




## Interval DP