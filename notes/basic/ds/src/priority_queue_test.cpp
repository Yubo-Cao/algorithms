#include <iostream>
#include <queue>

using namespace std;

int main() {
    // initialize. by default, it's a max heap
    priority_queue<int> q;
    // make a min heap. one may as well simply insert negative numbers, to use a
    // max heap as a min heap.
    priority_queue<int, vector<int>, greater<int>> q2;

    // push, append an element to the end of the queue
    q.push(1);
    q.push(2);

    // top, get the first element
    cout << q.top() << endl;  // 2

    // pop, remove the first element
    q.pop();

    return 0;
}