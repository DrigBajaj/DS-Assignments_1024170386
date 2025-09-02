#include <iostream>
#include <stack>
#include <string>
using namespace std;
int precedence(char op) {
    if (op == '+' || op == '-') 
        return 1;
    if (op == '*' || op == '/') 
        return 2;
    if (op == '^')
        return 3;
    return 0;
}
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
string infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
    	char ch = infix[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop();
        }
        else if (isOperator(ch)) {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                if (ch == '^' && s.top() == '^')
                    break;
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}
int main() {
    string infixExpr;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpr);
    string postfixExpr = infixToPostfix(infixExpr);
    cout << "Postfix expression: " << postfixExpr << endl;
    return 0;
}

