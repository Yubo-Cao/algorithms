#include <iostream>

using namespace std;

const int M = 1e6 + 10;

int e[M], tt = -1;
void push(int x) { e[++tt] = x; }
int pop() { return e[tt--]; }
bool empty() { return tt == -1; }
int query() { return e[tt]; }

int main() {
    int m;
    cin >> m;
    string op;
    int x;
    while (m--) {
        cin >> op;
        if (op == "push") cin >> x, push(x);
        else if (op == "pop") pop();
        else if (op == "empty") cout << (empty() ? "YES" : "NO") << endl;
        else if (op == "query") cout << query() << endl;
        else cout << "ERROR: Unknown operator '" << op << "'" << endl;
    }
    return 0;
}