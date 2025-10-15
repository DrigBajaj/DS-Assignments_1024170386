#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void interleaveQueue(queue<int> &q) {
    if (q.size() % 2 != 0) {
        cout << "Queue size must be even to interleave." << endl;
        return;
    }
    int halfSize = q.size() / 2;
    stack<int> s;
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < halfSize; i++) {
        q.push(q.front());
        q.pop();
    }
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}
int main() {
    queue<int> q;
    int n, val;
    cout << "Enter the number of elements (must be even): ";
    cin >> n;
    if (n % 2 != 0) {
        cout << "Number of elements must be even for interleaving." << endl;
        return 1;
    }
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }
    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
    interleaveQueue(q);
    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}

