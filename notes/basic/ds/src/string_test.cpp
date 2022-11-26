#include <iostream>

using namespace std;

int main() {
    // initialize
    string s;            // empty string with size 0
    string a = "hello";  // literal string

    // append
    a += ", anish";     // a = "hello, anish"
    a += 97;            // automatically convert int to char
    cout << a << endl;  // hello, anisha

    // size
    cout << a.size() << endl;  // 13

    // empty
    cout << a.empty() << endl;  // 0

    // substring
    cout << a.substr(0, 5) << endl;  // hello
    cout << a.substr(7) << endl;     // anisha, default to the end

    // c_str
    printf("%s\n", a.c_str());  // hello, anisha

    // find
    cout << a.find("anish") << endl;  // 7

    // clear
    a.clear();
    cout << a << endl;  // nothing

    return 0;
}