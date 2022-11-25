#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int i;
enum TOKEN_TYPE { NUMBER,
                  LPAREN,
                  RPAREN,
                  ADD,
                  SUB,
                  DIV,
                  MUL };

struct Token {
    TOKEN_TYPE t;
    int val;
};

bool is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

const int M = 1e5 + 10;

TOKEN_TYPE get_token_type(char c) {
    switch (c) {
        case '+':
            return ADD;
        case '-':
            return SUB;
        case '*':
            return MUL;
        case '/':
            return DIV;
        case '(':
            return LPAREN;
        case ')':
            return RPAREN;
        default:
            if (!isdigit(c)) cout << "ERROR: Unknown token type for character '" << c << "'" << endl;
    }
    return NUMBER;
}

vector<Token> tokenize(string s) {
    int idx = 0;
    vector<Token> r;
    while (idx < s.size()) {
        char c = s[idx];
        if (isspace(c)) {
            // do nothing
        } else if (is_operator(c)) {
            r.push_back({get_token_type(c), c});
        } else if (isdigit(c)) {
            int x = c - '0';
            while (isdigit(c = s[++idx]) && idx < s.size()) x = 10 * x + c - '0';
            r.push_back({NUMBER, x});
            continue;
        } else {
            throw invalid_argument("Invalid character in expression");
        }
        idx++;
    }
    return r;
}

enum NodeType {
    NUMBER_NODE,
    BINARY_EXPRESSION_NODE,
    PARENTHESIZED_EXPRESSION_NODE,
};

class Node {
   public:
    virtual NodeType get_type() = 0;
    virtual int eval() = 0;
    virtual string to_string() = 0;
};

class NumberNode : public Node {
   public:
    int val;
    NumberNode(int val) : val(val) {}
    NodeType get_type() override { return NUMBER_NODE; }
    int eval() override { return val; }
    string to_string() override { return std::to_string(val); }
};

class BinaryExpression : public Node {
   public:
    Node *left;
    Node *right;
    TOKEN_TYPE op;
    BinaryExpression(Node *left, Node *right, TOKEN_TYPE op) : left(left), right(right), op(op) {}
    NodeType get_type() override { return BINARY_EXPRESSION_NODE; }
    int eval() override {
        int l = left->eval();
        int r = right->eval();
        switch (op) {
            case ADD:
                return l + r;
            case SUB:
                return l - r;
            case MUL:
                return l * r;
            case DIV:
                return l / r;
            default:
                throw invalid_argument("Invalid operator");
        }
    }
    string to_string() override {
        string op_str;
        switch (op) {
            case ADD:
                op_str = "+";
                break;
            case SUB:
                op_str = "-";
                break;
            case MUL:
                op_str = "*";
                break;
            case DIV:
                op_str = "/";
                break;
            default:
                throw invalid_argument("Invalid operator");
        }
        return left->to_string() + " " + op_str + " " + right->to_string();
    }
};

class ParenExpression : public Node {
   public:
    Node *expr;
    ParenExpression(Node *expr) : expr(expr) {}
    NodeType get_type() override { return PARENTHESIZED_EXPRESSION_NODE; }
    int eval() override { return expr->eval(); }
    string to_string() override { return "(" + expr->to_string() + ")"; }
};

Node *atom(int &idx, vector<Token> &tokens);
Node *paren(int &idx, vector<Token> &tokens);
Node *term(int &idx, vector<Token> &tokens);
Node *expr(int &idx, vector<Token> &tokens);

Node *atom(int &idx, vector<Token> &tokens) {
    Token t = tokens[idx++];
    if (t.t == NUMBER) {
        return new NumberNode(t.val);
    } else if (t.t == LPAREN) {
        return paren(idx, tokens);
    } else {
        throw invalid_argument("Invalid token in expression");
    }
}

Node *paren(int &idx, vector<Token> &tokens) {
    Node *n = expr(idx, tokens);
    if (tokens[idx++].t != RPAREN) throw invalid_argument("Invalid token in expression");
    return new ParenExpression(n);
}

Node *expr(int &idx, vector<Token> &tokens) {
    Node *n = term(idx, tokens);
    while (idx < tokens.size()) {
        Token t = tokens[idx];
        if (t.t != ADD && t.t != SUB) break;
        idx++;
        n = new BinaryExpression(n, term(idx, tokens), t.t);
    }
    return n;
}

Node *term(int &idx, vector<Token> &tokens) {
    Node *n = atom(idx, tokens);
    while (idx < tokens.size()) {
        Token t = tokens[idx];
        if (t.t != MUL && t.t != DIV) break;
        idx++;
        n = new BinaryExpression(n, atom(idx, tokens), t.t);
    }
    return n;
}

Node *parse(string s) {
    try {
        vector<Token> tokens = tokenize(s);
        int idx = 0;
        return expr(idx, tokens);
    } catch (invalid_argument &e) {
        cout << "ERROR: " << e.what() << endl;
        return nullptr;
    }
}

int main() {
    string expr;
    getline(cin, expr);
    Node *root = parse(expr);
    if (root) cout << root->eval() << endl;
}