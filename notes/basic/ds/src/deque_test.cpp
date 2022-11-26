#include <iostream>
#include <queue>

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const deque<T> &d) {
    os << "[";
    for (int i = 0; i < d.size(); i++) {
        os << d[i];
        if (i != d.size() - 1) os << ", ";
    }
    os << "]";
    return os;
}

int main() {
    // intiailize
    deque<int> d;

    // size
    cout << d.size() << endl;  // 0

    // empty
    cout << d.empty() << endl;  // 1

    // clear
    d.clear();
    cout << d.empty() << endl;  // 1

    // push_back, append an element to the end of the deque
    d.push_back(1);
    d.push_back(2);

    // push_front, append an element to the front of the deque
    d.push_front(3);
    d.push_front(4);

    cout << d << endl;  // [4, 3, 1, 2]

    // front, get the first element
    cout << d.front() << endl;  // 4

    // back, get the last element
    cout << d.back() << endl;  // 2

    // pop_front, remove the first element
    d.pop_front();
    cout << d << endl;  // [3, 1, 2]

    // pop_back, remove the last element
    d.pop_back();
    cout << d << endl;  // [3, 1]

    // random access
    cout << d[0] << endl;     // 3
    cout << d.at(1) << endl;  // 1

    return 0;
}