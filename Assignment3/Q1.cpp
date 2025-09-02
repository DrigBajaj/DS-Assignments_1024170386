#include <iostream>
#include <stack>
using namespace std;
#define MAX_SIZE 5
void display(stack<int> s) {
    if (s.empty()) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack elements (top to bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main() {
    stack<int> s;
    int choice, value;
    do {
        cout << "\n*** STACK MENU ***" << endl;
        cout << "1. Push\n2. Pop\n3. Peek \n4. isEmpty\n5. isFull \n6. Display\n0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            if (s.size() >= MAX_SIZE) {
                cout << "Stack Overflow! Max size reached." << endl;
            } else {
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                cout << value << " pushed to stack." << endl;
            }
            break;
        case 2:
            if (s.empty()) {
                cout << "Stack Underflow! Cannot pop." << endl;
            } else {
                cout << s.top() << " popped from stack." << endl;
                s.pop();
            }
            break;
        case 3:
            if (s.empty()) {
                cout << "Stack is empty." << endl;
            } else {
                cout << "Top element is: " << s.top() << endl;
            }
            break;
        case 4:
            cout << (s.empty() ? "Stack is empty." : "Stack is not empty.") << endl;
            break;
        case 5:
            cout << (s.size() >= MAX_SIZE ? "Stack is full." : "Stack is not full.") << endl;
            break;
        case 6:
            display(s);
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);
    return 0;
}


