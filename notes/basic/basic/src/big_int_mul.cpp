#include <iostream>
#include <vector>

using namespace std;

// C = A * b. High precision number * low precision
vector<int> mul(vector<int> &A, int b) {
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++) {
        t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (t > 0) {
        C.push_back(t % 10);
        t /= 10;
    }
    return C;
}
// C = A * B. High precision number * high precision number
vector<int> mul(vector<int> &A, vector<int> &B) {
    vector<int> C(A.size() + B.size(), 0);
    for (int i = 0; i < A.size(); i++) {
        int t = 0;
        for (int j = 0; j < B.size(); j++) {
            t += C[i + j] + A[i] * B[j];
            C[i + j] = t % 10;
            t /= 10;
        }
        C[i + B.size()] = t;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main() {
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

    auto C = mul(A, b);

    for (int i = C.size() - 1; i >= 0; i--) printf("%d", C[i]);
    return 0;
}