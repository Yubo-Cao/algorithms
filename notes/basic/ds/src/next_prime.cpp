/**
 * Input format:
 * - First line, an arbitary number n.
 *
 * Output format:
 * - First line, the first prime number that's larger than n.
 */

#include <iostream>

typedef long long LL;

using namespace std;

int main() {
    LL n;
    cin >> n;
    for (LL i = n;; i++) {
        bool flag = true;
        for (LL j = 2; j * j <= n; j++) {
            if (i % j == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}