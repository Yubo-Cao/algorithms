#include <iostream>

using namespace std;

const int N = 100010;

class List {
    int e[N];        // value of the element
    int l[N], r[N];  // the left and right pointer of the element
    int idx;         // index of the next empty element

   public:
    List() {
        // since head and tail take up two elements, we start from 2
        idx = 2;
        // head and tail are 0, 1
        r[0] = 1;
        l[1] = 0;
    }

    void insert(int k, int x) {
        e[idx] = x;
        r[idx] = r[k];
        l[idx] = k;
        l[r[k]] = idx;
        r[k] = idx;
    }

    void insert_left(int k, int x) { insert(l[k], x); }

    int remove(int k) {
        r[l[k]] = r[k];
        l[r[k]] = l[k];
        int result = e[k];
        e[k] = 0;
        return result;
    }

    void print() {
        for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
        cout << endl;
    }
};

int main() {
    int m;
    cin >> m;
    List l;
    while (m--) {
        char cmd;
        cin >> cmd;
        int k, x;
        switch (cmd) {
            case 'H':
                cin >> x;
                l.insert(0, x);
                break;
            case 'I':
                cin >> k >> x;
                l.insert(k - 1, x);
                break;
            case 'D':
                cin >> k;
                l.remove(k - 1);
                break;
        }
    }
    l.print();
    return 0;
}