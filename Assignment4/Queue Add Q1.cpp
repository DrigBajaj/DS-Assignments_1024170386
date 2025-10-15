#include <iostream>
#include <queue>
using namespace std;
void generateBinaryNumbers(int n) {
    queue<string> q;
    q.push("1");
    for (int i = 1; i <= n; i++) {
        string curr = q.front();
        q.pop();
        cout << curr << (i == n ? "\n" : ", ");
        q.push(curr + "0");
        q.push(curr + "1");
    }
}
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Binary numbers from 1 to " << n << ": ";
    generateBinaryNumbers(n);
    return 0;
}

