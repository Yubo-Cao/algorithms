#include <iostream>

using namespace std;

const int M = 1e6 + 10;
int q[M], tt = -1, hh;
void enqueue(int x) { q[++tt] = x; }
int dequeue() { return q[hh++]; }
bool empty() { return hh > tt; }
int head() { return q[hh]; }
int tail() { return q[tt]; }

int main() {
    int m;
    cin >> m;
    string cmd;
    int x;
    while (m--) {
        cin >> cmd;
        if (cmd == "push") { cin >> x; enqueue(x); } 
        else if (cmd == "pop") { dequeue(); } 
        else if (cmd == "empty") { cout << (empty() ? "YES" : "NO") << endl; } 
        else { cout << head() << endl; }
    }

    return 0;
}