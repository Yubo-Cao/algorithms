#include <deque>
#include <iostream>

using namespace std;

void print_deque(deque<int> &d) {
    for (auto i : d) cout << i << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int a[n], i;
    for (i = 0; i < n; i++) cin >> a[i];
    deque<int> q;

    for (i = 0; i < n; i++) {
        if (q.size() && q.front() < i - k + 1) q.pop_front();
        while (q.size() && a[q.back()] >= a[i]) q.pop_back();
        q.push_back(i);
        if (i >= k - 1) cout << a[q.front()] << " ";
    }
    cout << endl, q.clear();
    for (i = 0; i < n; i++) {
        if (q.size() && q.front() < i - k + 1) q.pop_front();
        while (q.size() && a[q.back()] <= a[i]) q.pop_back();
        q.push_back(i);
        if (i >= k - 1) cout << a[q.front()] << " ";
    }
    return 0;
}