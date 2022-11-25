#include <iostream>

using namespace std;

int main()
{
    double x;
    cin >> x;

    double l = 0, r = x;
    while (r - l > 1e-6) // number of precision + 2; or just repeat for 100 times.
    {
        double mid = (l + r) / 2;
        if (mid * mid >= x)
            r = mid;
        else
            l = mid;
    }
    printf("%.2f\n", l); // 2 digits precision
    return 0;
}