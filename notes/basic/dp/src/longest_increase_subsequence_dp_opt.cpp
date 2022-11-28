#include <cstring>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;

    int a[n];  // the array
    int q[n];  // the min of each increasing subsequence
    memset(q, 0, sizeof q);
    for (int i = 0; i < n; i++) cin >> a[i];

    q[0] = -2e9;
    int len = 0;  // the max length of increasing subsequence
    for (int i = 0; i < n; i++) {
        int l = 0, r = len;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (q[mid] < a[i])
                l = mid;
            else
                r = mid - 1;
        }

        len = max(len, r + 1);
        q[r + 1] = a[i];
    }

    cout << len << endl;
    return 0;
}