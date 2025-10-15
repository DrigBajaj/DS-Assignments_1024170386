#include <iostream>
#include <queue>
using namespace std;
void sortQueue(queue<int> &q) {
    int n = q.size();
    for (int i = 0; i < n; i++) {
        int size = n - i;
        int prev = q.front();
        q.pop();
        for (int j = 1; j < size; j++) {
            int curr = q.front();
            q.pop();
            if (prev > curr) {
                q.push(curr);
            } else {
                q.push(prev);
                prev = curr;
            }
        }
        q.push(prev);
        for (int k = 0; k < i; k++) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
}
int main() {
    queue<int> q;
    int n, val;
    cout << "Enter number of elements in queue: ";
    cin >> n;
    cout << "Enter " << n << " elements:\n";
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
    cout << "\n";
    sortQueue(q);
    cout << "Sorted Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
    return 0;
}

