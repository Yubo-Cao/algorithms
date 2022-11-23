#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 3e5 + 10;

int n, m;
int a[N], s[N];

vector<int> alls;

typedef pair<int, int> PII;

vector<PII> add, query;

int descretize(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1;  // mapping to start from 1.
}

vector<int>::iterator unique(vector<int> &a) {
    int j = 0;
    for (int i = 0; i < a.size(); i++) {
        if (!i || a[i] != a[i - 1])  // !i, if it is the first eleents
            a[j++] = a[i];
    }
    return a.begin() + j;
}

int main() {
    cin >> n >> m;
    // read all number necessary
    for (int i = 0; i < n; i++) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});

        alls.push_back(l);
        alls.push_back(r);
    }

    // deduplicate & sort. prepare for descretize
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls), alls.end());

    // add
    for (auto item : add) {
        int x = descretize(item.first);
        a[x] += item.second;
    }

    // prefix sum
    for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

    // query
    for (auto item : query) {
        int l = descretize(item.first), r = descretize(item.second);
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}