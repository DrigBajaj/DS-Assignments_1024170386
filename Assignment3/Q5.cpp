#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;
int evaluatePostfix(const string& postfix) {
    stack<int> s;
    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            s.push(ch - '0');
        }
        else {
            if (s.size() < 2) {
                cerr << "Invalid postfix expression." << endl;
                return -1;
            }
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();

            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': 
                    if (val2 == 0) {
                        cerr << "Division by zero error." << endl;
                        return -1;
                    }
                    s.push(val1 / val2); 
                    break;
                default:
                    cerr << "Unsupported operator: " << ch << endl;
                    return -1;
            }
        }
    }
    if (s.size() != 1) {
        cerr << "Invalid postfix expression." << endl;
        return -1;
    }
    return s.top();
}
int main() {
    string postfixExpr;
    cout << "Enter a postfix expression (single-digit operands): ";
    getline(cin, postfixExpr);
    int result = evaluatePostfix(postfixExpr);
    if (result != -1)
        cout << "Result: " << result << endl;
    return 0;
}

