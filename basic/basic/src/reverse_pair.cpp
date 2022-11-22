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
pair<int, int> q[N], t[N];

void record_sort(pair<int, int> q[], int l, int r) {
    if (l >= r) return;
    int mid = l + r >> 1;
    record_sort(q, l, mid), record_sort(q, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (q[i] < q[j])
            t[k++] = q[i++];
        else
            t[k++] = q[j++];
    }
    while (j <= r) t[k++] = q[j++];
    while (i <= mid) t[k++] = q[i++];
    for (i = 0, j = l; j <= r;) q[j++] = t[i++];
}

int main() {
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        q[i] = make_pair(tmp, i);
    }
    record_sort(q, 0, n - 1);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(q[i].second - i);
    }
    printf("%d", sum / 2);
}