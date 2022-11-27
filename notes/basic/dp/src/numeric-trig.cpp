/**
 * Given a triangle, like this:
 *         7
 *       3   8
 *     8   1   0
 *   2   7   4   4
 * 4   5   2   6   5
 *
 * Where every step can be move to the node on it's right, or the node on it's
 * left. Find the maximum sum of the path from the top to the bottom.
 *
 * Input format:
 * - First line, a number N, the number of rows in the triangle. 1 <= N <= 500
 * - Next N lines, each line contains N numbers, the numbers in the triangle.
 *   Each number is larger than -10000 and smaller than 10000
 *
 * Output format:
 * - One line, the maximum sum of the path from the top to the bottom.
 *
 * Example Input:
 * 5
 * 7
 * 3 8
 * 8 1 0
 * 2 7 4 4
 * 4 5 2 6 5
 *
 * Example Output:
 * 30
 */

#include <iostream>

using namespace std;

const int INF = 1e5 + 10;

int main() {
    int n;
    cin >> n;

    int a[n][n];
    int f[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 2; j++) {
            f[i][j] = -INF;
        }
    }
    f[0][0] = a[0][0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            f[i][j] = f[i - 1][j] + a[i][j];
            if (j > 0) f[i][j] = max(f[i][j], f[i - 1][j - 1] + a[i][j]);
        }
    }

    int m = f[n - 1][0];
    for (int i = 0; i < n; i++) {
        m = max(f[n - 1][i], m);
    }
    cout << m << endl;
    return 0;
}