#include <iostream>

using namespace std;

const int N = 100010;

int stk[N], tt;

void push(int x) { stk[++tt] = x; }
int pop() { return stk[tt--]; }
bool empty() { return tt == 0; }
int peek() { return stk[tt]; }

int main() {
    int m;
    cin >> m;
    while (m--) {
        string op;
        int x;
        cin >> op;
        if (op == "push") {
            cin >> x;
            push(x);
        } else if (op == "pop") {
            pop();
        } else if (op == "empty") {
            cout << (empty() ? "YES" : "NO") << endl;
        } else if (op == "query") {
            cout << peek() << endl;
        }
    }
    return 0;
}