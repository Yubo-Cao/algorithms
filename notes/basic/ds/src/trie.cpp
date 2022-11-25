#include <iostream>

using namespace std;

const int N = 1e5 + 10;  // N is the maximum number of nodes in the trie
const int M = 26;        // size of alphabet

int trie[N][M];  // trie[i][j] is the index of the node that is the child of node i and has the label j
int cnt[N];      // cnt[i] is the number of words that end at node i
int idx;         // idx is the number of nodes in the trie. 0 is the root node and is empty

void insert(const char *s) {
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int u = s[i] - 'a';
        if (!trie[p][u]) trie[p][u] = ++idx;
        p = trie[p][u];
    }
    cnt[p]++;
}

int query(const char *s) {
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int u = s[i] - 'a';
        if (!trie[p][u]) return 0;
        p = trie[p][u];
    }
    return cnt[p];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        char op[2];
        string s;
        cin >> op >> s;
        switch (op[0]) {
            case 'I':
                insert(s.c_str());
                break;
            case 'Q':
                cout << query(s.c_str()) << endl;
                break;
            default:
                cout << "ERROR: Unknown operator '" << op[0] << "'" << endl;
        }
    }
    return 0;
}