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

const int N = 510, INF = 1e9;

int n;
int a[N][N], f[N][N];

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i + 1; j++) {  // must start from 0, to handle f[i - 1][j - 1]
            f[i][j] = -INF;
        }
    }

    f[1][1] = a[1][1];

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
        }
    }

    int res = -INF;
    for (int i = 1; i <= n; i++) {
        res = max(res, f[n][i]);
    }
    cout << res << endl;

    return 0;
}
