#include <iostream>
#include <vector>

using namespace std;

int cmp(vector<int> &A, vector<int> &B) {
    if (A.size() != B.size()) return A.size() > B.size();
    int i = 0, sz = A.size();
    for (int i = sz; i >= 0; i--)
        if (A[i] != B[i]) return A[i] - B[i];
    return 0;
}

vector<int> sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    for (int i = 0, t = 0; i < A.size(); i++) {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10) % 10);  // (t < 0)? t + 10: t. Notice if t >= 0, (t + 10) % 10 == t
        t = (t < 0) ? 1 : 0;         // if we need to get 1 off from previous 1.
    }

    while (C.size() > 1 && C.back() == 0) {
        C.pop_back();  // remove 0 follows, but keep 0 if 0 is answer.
    }
    return C;
}

int main() {
    string a, b;
    vector<int> A, B;

    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    if (cmp(A, B) > 0) {
        auto C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    } else {
        auto C = sub(B, A);
        cout << "-";
        for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    }
    return 0;
}