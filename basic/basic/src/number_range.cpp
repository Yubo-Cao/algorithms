#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int main() {
    int n, q;
    cin >> n >> q;

    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    while (q-- > 0) {
        int l = 0, h = n - 1, k;
        cin >> k;
        while (l < h) {
            int mid = l + h >> 1;
            if (a[mid] >= k)
                h = mid;
            else
                l = mid + 1;
        }
        if (a[l] != k) {
            cout << "-1 -1" << endl;
            continue;
        } else
            cout << l << " ";
        l = 0, h = n - 1;
        while (l < h) {
            int mid = l + h + 1 >> 1;
            if (a[mid] <= k)
                l = mid;
            else
                h = mid - 1;
        }
        cout << l << endl;
    }
}