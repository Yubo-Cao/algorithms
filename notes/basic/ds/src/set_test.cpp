#include <iostream>
#include <set>

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const set<T> &s) {
    os << "{";
    for (auto it = s.begin(); it != s.end(); it++) {
        os << *it;
        if (next(it) != s.end()) os << ", ";
    }
    os << "}";
    return os;
}

int main() {
    // initialize
    set<int> s;

    // insert
    s.insert(1);
    s.insert(2);
    s.insert(1);        // duplicate element will be ignored
    cout << s << endl;  // {1, 2}

    // size
    cout << s.size() << endl;  // 2

    // find. O(logn) time complexity
    // returns the iterator to the element if found, otherwise returns end()
    cout << *s.find(1) << endl;  // 1
    cout << *s.find(3) << endl;  // 2
    cout << *s.find(2) << endl;  // 2

    s.insert(3);
    s.insert(4);
    s.insert(5);
    cout << s << endl;  // {1, 2, 3, 4, 5}

    for (auto it = s.find(3); it != s.end(); it++) {
        cout << *it;
        if (next(it) != s.end()) cout << ", ";
    }
    cout << "}" << endl;  // 3, 4, 5}

    // erase all matching elements
    s.erase(3);
    cout << s << endl;  // {1, 2, 4, 5}
    // pass an iterator to erase. it would erase all elements in the iterator
    s.erase(s.find(4));
    cout << s << endl;  // {1, 2, 5}

    // lower_bound, returns the first element that is not less than the given
    // element. O(logn) time complexity
    cout << *s.lower_bound(2) << endl;  // 2
    cout << *s.lower_bound(3) << endl;  // 5

    // upper_bound, returns the first element that is greater than the given
    // element. O(logn) time complexity
    cout << *s.upper_bound(1) << endl;  // 2
    cout << *s.upper_bound(3) << endl;  // 5

    return 0;
}
