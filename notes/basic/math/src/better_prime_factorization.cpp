#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

vector<int> prime_factorizaton(int x) {
    vector<int> factors;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            int s = 0;
            do {
                x /= i;
                s++;
            } while (x % i == 0);
            while (s--) factors.push_back(i);
        }
    }
    if (x > 1) factors.push_back(x);
    return factors;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> factors = prime_factorizaton(n);
    for (auto i : factors) cout << i << " ";
    cout << endl;
    return 0;
}