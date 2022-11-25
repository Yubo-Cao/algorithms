#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;

int n, bv;
char p[N], s[M];
int ne[N];  // shadows std::next

int main() {
    cin >> n >> p + 1 >> bv >> s + 1;

    // find next
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;
        ne[i] = j;
    }

    // match
    for (int i = 1, j = 0; i <= bv; i++) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == n) {
            // success
            printf("%d ", i - n);
            j = ne[j];
        }
    }

    return 0;
}