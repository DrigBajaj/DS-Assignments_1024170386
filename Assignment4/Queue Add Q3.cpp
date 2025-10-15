#include <iostream>
#include <queue>
#include <stack>
using namespace std;
bool canSortQueue(queue<int> inputQ, int n) {
    stack<int> s;
    queue<int> outputQ;
    int expected = 1;
    while (!inputQ.empty()) {
        int front = inputQ.front();
        inputQ.pop();
        if (front == expected) {
            outputQ.push(front);
            expected++;
            while (!s.empty() && s.top() == expected) {
                outputQ.push(s.top());
                s.pop();
                expected++;
            }
        } else {
            if (!s.empty() && s.top() < front) {
                return false;
            }
            s.push(front);
        }
    }
    while (!s.empty()) {
        if (s.top() == expected) {
            outputQ.push(s.top());
            s.pop();
            expected++;
        } else {
            return false;
        }
    }
    return (expected == n + 1);
}
int main() {
    int n;
    cout << "Enter number of elements (n): ";
    cin >> n;
    queue<int> inputQ;
    cout << "Enter " << n << " elements (queue):\n";
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        inputQ.push(val);
    }
    if (canSortQueue(inputQ, n)) {
        cout << "Yes, queue can be sorted using stack.\n";
    } else {
        cout << "No, queue cannot be sorted using stack.\n";
    }
    return 0;
}

