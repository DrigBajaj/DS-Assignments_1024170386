#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}
bool areParenthesesBalanced(const string& expr) {
    stack<char> s;
    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty() || !isMatchingPair(s.top(), ch)) {
                return false;
            }
            s.pop();
        }
    }

    return s.empty();
}
int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);
    if (areParenthesesBalanced(expression)) {
        cout << "The expression has balanced parentheses." << endl;
    } else {
        cout << "The expression does NOT have balanced parentheses." << endl;
    }
    return 0;
}

