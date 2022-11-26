#include <iostream>
#include <vector>

using namespace std;

int main() {
    // initialize
    vector<int> a;         // empty vector with size 0
    vector<int> b(10);     // vector with size 10, all elements are 0
    vector<int> c(10, 1);  // vector with size 10, all elements are 1

    // iterate
    for (auto x : a) cout << x << ' ';
    cout << endl;  // nothing
    for (auto x : b) cout << x << ' ';
    cout << endl;  // a lot of 0
    for (auto x : c) cout << x << ' ';
    cout << endl;  // a lot of 1

    // size. number of elements O(1) time complexity
    cout << a.size() << endl;  // 0

    // empty, equivalent to size == 0
    cout << a.empty() << endl;  // 1

    // clear, remove all elements
    a.clear();

    // push_back, add an element to the end of the vector
    a.push_back(1);
    a.push_back(2);

    // front, get the first element
    cout << a.front() << endl;  // 1

    // back, get the last element
    cout << a.back() << endl;  // 2

    // pop_back, remove the last element
    a.pop_back();
    cout << a.back() << endl;  // 1

    // begin, end, get the iterator of the first element and the last element
    // an iterator can be treated as a pointer. end is the a[a.size()] (past 1 from end)
    a.push_back(2);
    for (auto it = a.begin(); it != a.end(); it++) cout << *it << ' ';
    cout << endl;

    // [] operator, get the element at the index
    cout << a[0] << endl;  // 1

    // comparison operator, compare the elements
    cout << (a == b) << endl;  // 0, because a and b are different
    cout << (a < b) << endl;   // 0, because 0 < 0 is false
    cout << (b < c) << endl;   // 1, beacuse 0 < 1 is true
}