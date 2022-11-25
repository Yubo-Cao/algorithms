#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int e[N], ne[N], head = -1, idx;

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

void remove(int k) {
    if (k == -1) {
        head = ne[head];
        return;
    }
    ne[k] = ne[ne[k]];
}

void print() {
    for (int i = head; i != -1; i = ne[i]) {
        printf("%d ", e[i]);
    }
    puts("");
}

int main() {
    int m;
    scanf("%d\n", &m);
    int k, x;
    char op;
    while (m--) {
        scanf("%c", &op);
        if (op == 'H')
            scanf("%d", &x), prepend(x);
        else if (op == 'D')
            scanf("%d", &k), remove(k - 1);
        else
            scanf("%d %d", &k, &x), insert(k - 1, x);
        scanf("\n");
    }
    print();
    return 0;
}