#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        float v, x;
        char c;
        cin >> v >> c >> x;
        if (x / v <= 1.0) {
            cout << "SWERVE";
        } else if (x / v <= 5.0) {
            cout << "BRAKE";
        } else {
            cout << "SAFE";
        }
        cout << endl;
    }
    return 0;
}