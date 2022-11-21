#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n;
int q[N];
int tmp[N];

void msort(int q[], int l, int r)
{
    // 0, 1 end recursion
    if (l >= r)
        return;
    int mid = l + r >> 1;

    // sort left and right
    msort(q, l, mid);
    msort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    // merge
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++];
    }
    // left over
    while (i <= mid)
        tmp[k++] = q[i++];
    while (j <= r)
        tmp[k++] = q[j++];
    // copy back
    for (i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &q[i]);
    msort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", q[i]);
    return 0;
}