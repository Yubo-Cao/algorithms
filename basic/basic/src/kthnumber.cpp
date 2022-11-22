/*
Given an integer sequence of length n and an integer k, please use the quick
selection algorithm to find the kth number of the sequence sorted from small to
large.

input format

- The first line contains two integers n and k.
- The second line contains n integers (all integers in the range 1∼109),
representing the sequence of integers.
*/
#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n, k;
int q[N];

int qsel(int q[], int l, int r, int k) {
    if (l >= r) return q[l];
    int x = q[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        while (q[++i] < x) {}
        while (q[--j] > x) {}
        if (i < j) swap(q[i], q[j]);
    }
    int s = j - l + 1;                        // number of elements in left
    if (k <= s) { return qsel(q, l, j, k); }  // only sort left part
    else                                      // or, if k is larger than pivot, right part
        return qsel(q, j + 1, r, k - s);      // ∴ O(n) n × (1 + 1/2 + …)  = 2n
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> q[i];
    cout << qsel(q, 0, n - 1, k) << endl;
}