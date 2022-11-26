#include <iostream>
#include <queue>

using namespace std;

int main() {
    // initialize
    queue<int> q;

    // push, append an element to the end of the queue
    q.push(1);
    q.push(2);

    // front, get the first element
    cout << q.front() << endl;  // 1

    // back, get the last element
    cout << q.back() << endl;  // 2

    // pop, remove the first element
    q.pop();
    cout << q.front() << endl;  // 2

    // size. number of elements O(1) time complexity
    cout << q.size() << endl;  // 1

    // empty, equivalent to size == 0
    cout << q.empty() << endl;  // 0

    // queue does not have clear, however, we can clear them by recreating 1.
    q = queue<int>();
    cout << q.empty() << endl;  // 1
    
    return 0;
}
