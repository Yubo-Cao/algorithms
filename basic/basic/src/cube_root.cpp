#include <iostream>

using namespace std;

const double EPS = 1e-8;

int main() {
    double x;
    cin >> x;

    double l = -1e6, r = 1e6;
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= x)
            r = mid;
        else
            l = mid;
    }
    printf("%lf\n", l);
    return 0;
}