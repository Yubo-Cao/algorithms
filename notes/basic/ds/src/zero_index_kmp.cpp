// This fails to pass all test cases

#include <iostream>

using namespace std;

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n; cin >> n; char p[n]; cin >> p;
    int m; cin >> m; char s[m]; cin >> s;
    int next[n] = {-1};

    for (int i = 1, j = -1; i < n; i++) {
        while (j >= 0 && p[i] != p[j + 1]) j = next[j];
        if (p[i] == p[j + 1]) j++;
        next[i] = j;
    }

    for (int i = 0, j = -1; i < m; i++) {
        while (j >= 0 && s[i] != p[j + 1]) j = next[j];
        if (s[i] == p[j + 1]) j++;
        if (j == n - 1) {
            cout << i - j << " ";
            j = next[j];
        }
    }

    return 0;
}