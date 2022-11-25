/*
Given an array of integers of length n, please count the number of reversed
pairs in the array.

The definition of reverse pair is as follows: for the i-th and j-th elements of
the sequence, if i<j and a[i]>a[j], then it is a reverse pair; otherwise, it is
not.

input format:
The first line contains the integer n, indicating the length of the
sequence.
The second line contains n integers representing the entire sequence.

output format:
Output an integer representing the number of reversed pairs.
*/

#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n;
int q[N], t[N];

long reverse_pair(int q[], int l, int r) {  // 1e6 * (1e6 - 1) ∼ 1e12 < 2^63 - 1
    if (l >= r) return 0;
    int m = l + r >> 1;
    long result = reverse_pair(q, l, m) + reverse_pair(q, m + 1, r);
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r) {
        if (q[i] <= q[j])
            t[k++] = q[i++];
        else {
            t[k++] = q[j++];
            result += m - i + 1;  // all the elements, including i is in wrong position
        }
    }
    while (i <= m) t[k++] = q[i++];
    while (j <= r) t[k++] = q[j++];
    for (i = l, j = 0; i <= r; i++, j++) q[i] = t[j];
    return result;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    cout << reverse_pair(q, 0, n - 1);
    return 0;
}