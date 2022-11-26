#include <iostream>

using namespace std;

int find(int p[], int x)
{
    int r = x;
    while (p[r] != r)
        r = p[r];
    while (p[x] != x)
    {
        int y = p[x];
        p[x] = r;
        x = y;
    }
    return r;
}

int find_recursion(int p[], int x){
    if (p[x] == x) return x;
    else return p[x] = find_recursion(p, p[x]);
}

int main()
{
    int n, m;
    cin >> n >> m;

    int p[n];
    for (int i = 0; i <= n; i++)
        p[i] = i;

    while (m--)
    {
        char op;
        int a, b;
        cin >> op >> a >> b;

        switch (op)
        {
        case 'M':
            p[find(p, a)] = find(p, b);
            break;
        case 'Q':
            if (find(p, a) == find(p, b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            break;
        default:
            cout << "ERROR" << endl;
        }
    }

    return 0;
}