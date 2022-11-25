#include <iostream>

using namespace std;

const int N = 100010;

class List {
    int head;   // index of the first element
    int e[N];   // value of the element
    int ne[N];  // index of the next element
    int idx;    // index of the next empty element

   public:
    List() {
        head = -1;
        idx = 0;
    }

    void prepend(int x) {
        e[idx] = x;
        ne[idx] = head;
        head = idx;
        idx++;
    }

    void insert(int k, int x) {
        e[idx] = x;
        ne[idx] = ne[k];
        ne[k] = idx;
        idx++;
    }

    void append(int x) {
        if (head == -1) {
            prepend(x);
            return;
        }
        int k = head;
        while (ne[k] != -1) k = ne[k];
        insert(k, x);
    }

    void remove(int k) {
        if (k == head) {
            head = ne[k];
            return;
        }
        ne[k] = ne[ne[k - 1]];
        // one may optimize this and reuse idx.
        // memory leak is ignored in algorithm questions.
    }

    void print() {
        for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
        cout << endl;
    }
};

int main() {
    int m;
    cin >> m;
    List l;

    while (m--) {
        char op;
        int k, x;
        cin >> op;
        switch (op) {
            case 'H':
                cin >> x;
                l.prepend(x);
                break;
            case 'D':
                cin >> k;
                l.remove(k - 1);
                break;
            case 'I':
                cin >> k >> x;
                l.insert(k - 1, x);
        }
    }
    l.print();
    return 0;
}
