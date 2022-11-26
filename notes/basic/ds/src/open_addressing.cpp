#include <iostream>
#include <cstring>

using namespace std;

const int N = 300007;
const int NU = 0x3f3f3f3f;

int h[N];

int ha(int x) {
    return (x % N + N) % N;
}

/**
 * Return the location of element. If not exists,
 * return the location where the element should be inserted.
 * 
 * WARNING: h is full, this function will never return.
 */
int find(int x) {
    int k = ha(x);
    while (h[k] != NU && h[k] != x) {
        k++;
        if (k == N) k = 0;  // already reached end. cycle back.
    }
    return k;
}

void insert(int x) {
    h[find(x)] = x;
}

bool contains(int x) {
    return h[find(x)] != NU;
}

int main() {
    int n;
    cin >> n;
    memset(h, NU, sizeof h);

    string op;
    int x;
    while (n--) {
        cin >> op >> x;
        if (op == "I")
            insert(x);
        else
            cout << (contains(x) ? "Yes" : "No") << endl;
    }

    return 0;
}
