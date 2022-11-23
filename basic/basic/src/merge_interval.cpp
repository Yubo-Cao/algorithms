#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> intervals, results;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        intervals.push_back({l, r});
    }

    sort(intervals.begin(), intervals.end());

    int l = intervals[0].first, r = intervals[0].second;
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].first <= r) {
            r = max(r, intervals[i].second);
        } else {
            results.push_back({l, r});
            l = intervals[i].first;
            r = intervals[i].second;
        }
    }

    results.push_back({l, r});

    for (auto item : results) {
        cout << item.first << " " << item.second << endl;
    }

    return 0;
}