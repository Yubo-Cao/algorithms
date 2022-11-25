/**
 * Given an array of size n ≤ 10⁶.
 *
 * There is a sliding window of size k that moves from the leftmost to the
 * rightmost of the array. You can only see k numbers in the window. Each time
 * the sliding window moves one position to the right.
 *
 * Your task is to determine the maximum and minimum values in the window at
 * each position of the sliding window.
 *
 * Input format:
 * - The first line contains two integers n and k, representing the length of
 *   the array and the length of the sliding window, respectively.
 * - The second line has n integers, representing the specific value of the
 *   array.
 *
 * Output format:
 * - The first line outputs, from left to right, the minimum value in the
 *   sliding window at each position.
 * - The second line outputs, from left to right, the maximum value in the
 *   sliding window at each position.
 */

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