#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v; 
    while (n != 0) {
        int x;
        cin >> x;
        v.push_back(x);
        n--;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != i + 1) {
            cout << i + 1;
            return 0;
        }
    }
    return 0;
}
