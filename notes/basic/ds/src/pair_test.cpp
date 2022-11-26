#include <iostream>

using namespace std;

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

int main() {
    // initialize
    pair<int, string> p;
    p.first = 1, p.second = "hello";               // hand written
    pair<int, string> p2 = make_pair(2, "world");  // make_pair
    pair<int, string> p3(3, "yubo");               // constructor
    pair<int, string> p4 = {4, "anish"};           // and {}

    // print pair (notice that's because our meta programming)
    cout << p << " " << p2 << " " << p3 << " " << p4 << endl;

    // pair support comparison operator. it compares the first element first,
    // then the second element, in dictionary order.
    cout << (p < p2) << endl;   // 1
    cout << (p3 < p2) << endl;  // 0

    // pair can store arbitary number of elements, if you nest them.
    pair<int, pair<int, int>> p5 = {1, {2, 3}};
    cout << p5 << endl;  // (1, (2, 3))
}