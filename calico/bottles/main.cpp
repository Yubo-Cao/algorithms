#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int s;
int c[N];
int idx[N];  // record the re-ordered index
int tmp[N];

void msort(int l, int r) {
    if (l >= r) return;
    int mid = l + r >> 1;
    msort(l, mid);
    msort(mid + 1, r);
    // record the re-ordered index
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (c[idx[i]] < c[idx[j]])
            tmp[k++] = idx[i++];
        else
            tmp[k++] = idx[j++];
    }
    while (i <= mid) tmp[k++] = idx[i++];
    while (j <= r) tmp[k++] = idx[j++];
    for (int i = l, j = 0; i <= r; i++, j++) idx[i] = tmp[j];
}

int wait_time() {
    int res = 0, last = 0;
    for (int i = 1; i <= s; i++) {
        res += last + c[idx[i]];
        last += c[idx[i]];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        cin >> s;  // number of students
        for (int i = 1; i <= s; i++) cin >> c[i], idx[i] = i;

        msort(1, s);
        cout << wait_time() << endl;
        for (int i = 1; i <= s; i++) cout << idx[i] << ' ';
        cout << endl;
    }
    return 0;
}