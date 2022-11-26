#include <iostream>
#include <stack>

using namespace std;

int main() {
    // initialize
    stack<int> s;

    // push, append an element to the end of the stack
    s.push(1);
    s.push(2);

    // top, get the last element
    cout << s.top() << endl;  // 2

    // pop, remove the last element
    s.pop();

    // size. number of elements O(1) time complexity
    cout << s.size() << endl;  // 1

    // empty, equivalent to size == 0
    cout << s.empty() << endl;  // 0

    return 0;
}