#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int n;
int q[N], t[N];

void msort(int q[], int l, int r) {
    if (l >= r) return;
    int mid = l + r >> 1;
    msort(q, l, mid);
    msort(q, mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j])
            t[k++] = q[i++];
        else
            t[k++] = q[j++];
    }
    while (j <= r) t[k++] = q[j++];
    while (i <= mid) t[k++] = q[i++];
    i = 0, j = l;
    while (j <= r) q[j++] = t[i++];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    msort(q, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", q[i]);
    return 0;
}