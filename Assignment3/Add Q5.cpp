#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
bool canSortUsingStack(vector<int> A) {
    vector<int> sortedA(A);
    sort(sortedA.begin(), sortedA.end());
    stack<int> S;
    int i = 0;
    int j = 0;
    int n = (int)A.size();
    while (i < n || !S.empty()) {
        if (!S.empty() && S.top() == sortedA[j]) {
            S.pop();
            j++;
        }
        else if (i < n) {
            S.push(A[i]);
            i++;
        }
        else {
            return false;
        }
    }
    return true;
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> A;
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        A.push_back(val);
    }
    if (canSortUsingStack(A)) {
        cout << "Yes, it is possible to sort using the stack\n";
    }
    else {
        cout << "No, it is not possible to sort using the stack\n";
    }
    return 0;
}

