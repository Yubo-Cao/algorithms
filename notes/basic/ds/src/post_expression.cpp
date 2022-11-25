/**
 * Convert a mid-fix expression to a post-fix expression.
*/
#include <iostream>

using namespace std;

int main() {
    string expr;
    cin >> expr;
    int len = expr.length();
    char *post_expr = new char[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        if (expr[i] == '(') {
            post_expr[++top] = expr[i];
        } else if (expr[i] == ')') {
            while (post_expr[top] != '(') {
                cout << post_expr[top--];
            }
            top--;
        } else if (expr[i] == '+' || expr[i] == '-') {
            while (top != -1 && post_expr[top] != '(') {
                cout << post_expr[top--];
            }
            post_expr[++top] = expr[i];
        } else if (expr[i] == '*' || expr[i] == '/') {
            while (top != -1 && (post_expr[top] == '*' || post_expr[top] == '/')) {
                cout << post_expr[top--];
            }
            post_expr[++top] = expr[i];
        } else {
            cout << expr[i];
        }
    }

    while (top != -1) {
        cout << post_expr[top--];
    }
    return 0;
}