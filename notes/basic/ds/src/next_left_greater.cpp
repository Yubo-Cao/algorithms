/**
 * Given a sequence of integers of length N, output the first smaller number to
 * the left of each number, or −1 if it does not exist.
 *
 * Input format:
 * - The first line contains the integer N, representing the length of the
 *   sequence.
 * - The second line contains N integers, representing the sequence of integers.
 *
 * Output format:
 * - A total of one line, containing N integers, where the i-th number
 *   represents the first number on the left of the i-th number that is smaller
 *   than it, and if it does not exist, output −1.
 */

#include <iostream>

using namespace std;

const int N = 1e6 + 10;
int stk[N], tt;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (tt && stk[tt] >= x) tt--;
        if (tt)
            cout << stk[tt] << ' ';
        else
            cout << -1 << ' ';
        stk[++tt] = x;
    }

    return 0;
}