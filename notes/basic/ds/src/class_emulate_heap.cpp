#include <algorithm>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Heap {
    int *h;    // storage of elements in heap
    int *ph;   // order of insertion -> index of element in heap
    int *hp;   // index of element in heap -> order of insertion
    int size;  // the size of the heap
    int m;     // m-th insertion

    void swap(int a, int b) {
        std::swap(ph[hp[a]], ph[hp[b]]);
        std::swap(hp[a], hp[b]);
        std::swap(h[a], h[b]);
    }

    void down(int u) {
        while (u * 2 <= size) {
            int t = u * 2;
            if (t + 1 <= size && h[t + 1] < h[t]) t++;
            if (h[t] >= h[u]) break;
            swap(t, u);
            u = t;
        }
    }

    void up(int u) {
        while (u / 2 && h[u / 2] > h[u]) {
            swap(u / 2, u);
            u /= 2;
        }
    }

   public:
    Heap(int n) {
        h = new int[n + 1];
        ph = new int[n + 1];
        hp = new int[n + 1];
        size = 0;
        m = 0;
    }
    ~Heap() {
        delete h;
        delete ph;
        delete hp;
    }

    void insert(int x) {
        size++, m++;
        ph[m] = size;
        hp[size] = m;
        h[size] = x;
        up(size);
    }
    int min() {
        return h[1];
    }
    void remove(int k) {
        swap(k, size);
        size--;
        down(k), up(k);
    }
    void remove_nth(int k) {
        remove(ph[k]);
    }
    void remove_min() {
        swap(1, size);
        size--;
        down(1);
    }
    void modify(int k, int x) {
        h[k] = x;
        down(k), up(k);
    }
    void modify_nth(int k, int x) {
        modify(ph[k], x);
    }
    void print() {
        int level = 1;
        for (int i = 1; i <= size; i++) {
            if (i == level) {
                cout << endl;
                level *= 2;
            }
            cout << h[i] << " ";
        }
        cout << endl;
        cout << min() << " " << size << endl;
    }
};

int main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    Heap h = Heap(n);

    string op;
    int k, x;
    while (n--) {
        cin >> op;
        if (op == "I") {
            cin >> x;
            h.insert(x);
        } else if (op == "PM") {
            cout << h.min() << endl;
        } else if (op == "DM") {
            h.remove_min();
        } else if (op == "D") {
            cin >> k;
            h.remove_nth(k);
        } else if (op == "C") {
            cin >> k >> x;
            h.modify_nth(k, x);
        } else {
            cout << "ERROR: Invalid command '" << op << "'" << endl;
            return -1;
        }
    }
    return 0;
}