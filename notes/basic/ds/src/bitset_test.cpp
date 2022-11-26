#include <bitset>
#include <iostream>

using namespace std;

template <size_t N>
ostream& operator<<(ostream& os, const bitset<N>& bs) {
    os << "[";
    for (size_t i = 0; i < N; ++i) {
        os << bs[i];
        if (i < N - 1) os << ", ";
    }
    os << "]";
    return os;
}

int main() {
    // initialize
    bitset<5> s;                // generic type is used as size of set.
    cout << s << endl;          // [0, 0, 0, 0, 0]
    cout << ~s << endl;         // [1, 1, 1, 1, 1]
    s[0] = 1;                   // set 0th bit
    cout << (s << 1) << endl;   // [0, 1, 0, 0, 0]
    cout << (s >> 1) << endl;   // [0, 0, 0, 0, 0]
    cout << (s << 2) << endl;   // [0, 0, 1, 0, 0]
    cout << s.count() << endl;  // 1, number of 1
    cout << s.size() << endl;   // 5, size of set
    cout << s.test(0) << endl;  // 1, test 0th bit
    cout << s.any() << endl;    // 1, any bit is 1
    s.reset();                  // reset all to 0
    cout << s << endl;          // [0, 0, 0, 0, 0]
    cout << s.none() << endl;   // 1, test if all bits are 0
    s.flip();                   // flip all bits
    cout << s << endl;          // [1, 1, 1, 1, 1]
    s.set(0, 0);                // 0 is set to 0
    cout << s << endl;          // [0, 1, 1, 1, 1]
    return 0;
}