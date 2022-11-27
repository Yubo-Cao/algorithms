#include <iostream>

using namespace std;

const int N = 21;
typedef long long ll;

int bx, by, cx, cy;

bool horseReach(int x, int y) {
    int dx[] = {0, -2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {0, 1, -1, 2, -2, 2, -2, 1, -1};
    bool flag = false;
    for (int i = 0; i < 9; i++) {
        if (cx + dx[i] == x && cy + dy[i] == y) {
            flag = true;
            break;
        }
    }
    return flag;
}

ll dp[N][N];

ll solve() {
    dp[0][0] = 1;
    for (int i = 0; i <= bx; i++) {
        for (int j = 0; j <= by; j++) {
            if (horseReach(i, j)) {
                dp[i][j] = 0;
                continue;
            }
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
        }
    }
    return dp[bx][by];
}

int main() {
    cin >> bx >> by >> cx >> cy;
    cout << solve() << endl;
    return 0;
}