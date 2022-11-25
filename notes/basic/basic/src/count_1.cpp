#include <iostream>

using namespace std;

int lowbit(int x) { return x & -x; }

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;

        int result = 0;
        while (x) x -= lowbit(x), result++;
        cout << result << " ";
    }
    cout << endl;
}