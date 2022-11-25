/**
 * Give a integer sequence, find the longest continuous sequence that doesn't
 * contain any duplicate number.
 *
 * Input format:
 * - The first line contains an integer N, the length of the sequence.
 * - The second line contains N integers, the sequence.
 *
 * Output format:
 * - A single line contains two integers, the length of the longest continuous
 */

#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n;
int vis[N], a[N];

bool has_duplicate(int s[], int l, int h) {
    bool vis[N] = {false};
    for (int i = l; i <= h; i++) {
        if (vis[s[i]]) {
            return true;
        }
        vis[s[i]] = true;
    }
    return false;
}

int brute_force(int s[]) {
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++) {
            if (!has_duplicate(s, j, i)) {
                ans = max(ans, i - j + 1);
            }
        }
    return ans;
}

int two_pointer(int s[]) {
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        vis[s[i]]++;
        while (vis[s[i]] > 1) vis[s[j++]]--;
        ans = max(ans, i - j + 1);
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << two_pointer(a);
    return 0;
}