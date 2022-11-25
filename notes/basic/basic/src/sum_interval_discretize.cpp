#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

vector<PII> add, query;
vector<int> all;

const int N = 3e5 + 1;

int find(vector<int> &all, int x) {
    int l = 0, r = all.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (all[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1;
}

int main() {
    int n, m;
    cin >> n >> m;

    while (n--) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});

        all.push_back(x);
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});

        all.push_back(l);
        all.push_back(r);
    }

    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    int s[N] = {0};

    for (auto x : add) {
        int i = find(all, x.first);
        s[i] += x.second;
    }

    for (int i = 0; i < N; i++) s[i] += s[i - 1];

    for (auto x : query) {
        int l = find(all, x.first), r = find(all, x.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}