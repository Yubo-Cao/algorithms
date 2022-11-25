#include <iostream>

using namespace std;

const int M = 1e6 + 10;

int e[M], l[M], r[M], idx;

void init() {
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

void add(int k, int x) {
    e[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

void remove(int k) {
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

void prepend(int x) { add(0, x); }

void append(int x) { add(l[1], x); }

void add_left(int k, int x) { add(l[k + 1], x); }

void add_right(int k, int x) { add(k + 1, x); }

int main() {
    int m;
    cin >> m;
    init();
    while (m--) {
        char op[3];
        int k, x;
        cin >> op;
        switch (op[0]) {
            case 'L':
                cin >> x;
                prepend(x);
                break;
            case 'R':
                cin >> x;
                append(x);
                break;
            case 'D':
                cin >> k;
                remove(k + 1);
                break;
            case 'I':
                cin >> k >> x;
                if (op[1] == 'L') {
                    add_left(k, x);
                } else {
                    add_right(k, x);
                }
                break;
            default:
                cout << "ERROR: Unknown operator " << op << endl;
        }
    }

    for (int i = r[0]; i != 1; i = r[i]) {
        cout << e[i] << " ";
    }
    cout << endl;
    return 0;
}