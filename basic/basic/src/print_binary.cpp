#include <string.h>

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n > 0) {
        cout << (n & 1);
        n >>= 1;
    }
    return 0;
}