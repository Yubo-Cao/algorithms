/*
ID: cao20061
PROG: gift1
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    ifstream fin("gift1.in");
    ofstream fout("gift1.out");

    int np;
    fin >> np;

    vector<string> friends;
    unordered_map<string, int> final_money;
    unordered_map<string, int> original_money;
    for (int i = 0; i < np; i++) {
        string name;
        fin >> name;
        friends.push_back(name);
    }
    for (int i = 0; i < np; i++) {
        string name;
        fin >> name;
        int money, friend_count;
        fin >> money >> friend_count;
        if (!friend_count) continue;

        final_money[name] += money % friend_count;
        original_money[name] = money;

        for (int j = 0; j < friend_count; j++) {
            string friend_name;
            fin >> friend_name;
            final_money[friend_name] += money / friend_count;
        }
    }
    for (auto name : friends) {
        fout << name << " " << (final_money[name] - original_money[name]) << endl;
    }
    return 0;
}
