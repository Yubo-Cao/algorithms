#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> intervals;
    while (n--) {
        int l, r;
        cin >> l >> r;
        intervals.push_back({l, r});
    }

    sort(intervals.begin(), intervals.end());

    int l = intervals[0].first, r = intervals[0].first, count = 1;
    for (auto x : intervals) {
        if (x.first <= r)
            r = max(x.second, r);
        else {
            count++;
            l = x.first;
            r = x.second;
        }
    }
    cout << count;
    return 0;
}