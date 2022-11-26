#include <iostream>
#include <map>

using namespace std;

template <typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &m) {
    os << "{";
    for (auto it = m.begin(); it != m.end(); it++) {
        os << it->first << ": " << it->second;
        if (next(it) != m.end()) os << ", ";
    }
    os << "}";
    return os;
}

template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}

int main() {
    // initialize
    map<int, int> m;

    // insert
    m.insert({1, 2});   // insert a pair
    m[2] = 3;           // equivalent to m.insert({2, 3});
    m[1] = 4;           // duplicate key will overwrite the value
    cout << m << endl;  // {1: 4, 2: 3}

    // size
    cout << m.size() << endl;  // 2

    // find. O(logn) time complexity
    cout << *m.find(1) << endl;  // (1, 4)
    cout << *m.find(3) << endl;  // (2, 0). return end iterator
    cout << *m.find(2) << endl;  // (2, 3)

    // erase all matching elements
    m.erase(2);
    cout << m << endl;  // {1: 4}

    // upper & lower bound
    m[2] = 3;
    m[3] = 4;
    cout << m << endl;                  // {1: 4, 2: 3, 3: 4}
    cout << *m.lower_bound(1) << endl;  // (1, 4)
    cout << *m.upper_bound(1) << endl;  // (2, 3)
    return 0;
}