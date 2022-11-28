#include <bitset>
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int primes[N], cnt;
bitset<N> st;

void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] <= n; j += i) st[primes[j] * i] = 1;
    }
}
