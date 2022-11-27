#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
int c[N];

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << endl;
}

void solve() {
    int n, k;
    cin >> n >> k;

    int st[n], ed[n], max_end = 0;

    // ending position of each sequence
    for (int i = 0; i < n; i++) {
        cin >> ed[i];
        ed[i] -= 1;
        max_end = max(max_end, ed[i]);
    }
    // starting position of each sequence
    for (int i = 0; i < n; i++) {
        cin >> st[i];
        st[i]--;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> s;
    for (int i = 0; i < n; i++) { s.push({st[i], ed[i]}); }

    priority_queue<int, vector<int>, greater<int>> e;

    // c is the number of sequence that's still active at time i
    int count = 0;
    for (int i = 0; i < max_end; i++) {
        while (!s.empty() && s.top().first == i) {
            e.push(s.top().second);
            s.pop();
            count++;
        }
        while (!e.empty() && e.top() == i) {
            e.pop();
            count--;
        }
        c[i] = count;
    }

    // sliding window to find a window that sum up to k;
    int l = 0, r = 0;
    int sum = 0;
    pair<int, int> res = {-1, -1};
    while (r < max_end) {
        sum += c[r];
        while (sum > k) sum -= c[l++];
        if (sum == k) {
            res = {l, r};
            break;
        }
        r++;
    }
    if (res.first == -1)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << res.first + 1 << ' ' << res.second + 2 << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) solve();
    return 0;
}