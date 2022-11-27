/*
ID: cao20061
PROG: ride
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

int mod(string s, int m) {
    int res = 1;
    for (int i = 0; i < s.size(); i++)
        res = (res * (s[i] - 'A' + 1)) % m;
    return res;
}

int main() {
    ifstream fin("ride.in");
    ofstream fout("ride.out");

    string a, b;
    fin >> a >> b;
    fout << (mod(a, 47) == mod(b, 47) ? "GO" : "STAY") << endl;
    return 0;
}