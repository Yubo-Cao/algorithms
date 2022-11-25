#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

stack<int> num;
stack<char> op;
unordered_map<char, int> PRECEDENCE{
    {'+', 1},
    {'-', 1},
    {'*', 2},
    {'/', 2},
};

void eval() {
    auto b = num.top();
    num.pop();
    auto a = num.top();
    num.pop();
    auto c = op.top();
    op.pop();
    int x;
    if (c == '+')
        x = a + b;
    else if (c == '-')
        x = a - b;
    else if (c == '*')
        x = a * b;
    else
        x = a / b;
    num.push(x);
}

int main() {
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        auto c = str[i];
        if (isdigit(c)) {
            int x = 0, j = i;
            while (j < str.size() && isdigit(str[j]))
                x = x * 10 + str[j++] - '0';
            i = j - 1;
            num.push(x);
        } else if (c == '(')
            op.push(c);
        else if (c == ')') {
            // evaluate all expressions inside the parenthesis.
            while (op.top() != '(') eval();
            op.pop();
        } else {
            // any operators
            while (op.size() && PRECEDENCE[op.top()] >= PRECEDENCE[c])
                // if we walk up to the AST, then evaluate the iterated left child
                eval();
            op.push(c);
        }
    }

    while (op.size()) eval();
    cout << num.top() << endl;
    return 0;
}
