#include <iostream>

using namespace std;
typedef long long ll;

int bx, by, cx, cy;
ll cnt;

const int N = 21;

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

void dfs(int x, int y) {
    if (x == bx && y == by) {
        cnt++;
        return;
    }
    if (x > bx || y > by) {
        return;
    }
    if (!horseReach(x + 1, y)) dfs(x + 1, y);
    if (!horseReach(x, y + 1)) dfs(x, y + 1);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    cin >> bx >> by >> cx >> cy;
    dfs(0, 0);
    cout << cnt << endl;
    return 0;
}