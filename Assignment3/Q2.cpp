#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    string input = "DataStructure";
    stack<char> s;
    for (int i=0;i<input.length();i++) {
        s.push(input[i]);
    }
    string reversed = "";
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }
    cout << "Reversed string: " << reversed << endl;
    return 0;
}

