#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n, bv;
int a[N], s[N];

int main() {
    scanf("%d%d", &n, &bv);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    // s[0] = 0; global variable default initialize to all 0.
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    while (bv--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l - 1]);
    }
    return 0;
}