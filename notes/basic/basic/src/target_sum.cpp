/**
 * Give 2 sorted arrays A & B that is sorted in ascending order, and a target
 * value x. Find a pair of numbers from A & B that sum to x.
 *
 * Input format:
 * - Line 1: n, m, x. The size of A & B, and the target value.
 * - Line 2: n integers, the elements of A.
 * - Line 3: m integers, the elements of B.
 *
 * Output format:
 * - Line 1: a, b. The index of the pair of numbers from A & B that sum to x.
 */

#include <iostream>

using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    int a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    for (int i = 0, j = m - 1; i < n; i++) {
        while (j >= 0 && a[i] + b[j] > x) j--;
        if (a[i] + b[j] == x) cout << i << " " << j << endl;
    }
    return 0;
}