#include <bits/stdc++.h>
using namespace std;
vector<int> prevSmaller(const vector<int>& A) {
    vector<int> result;
    stack<int> s;
    for (int i = 0; i < A.size(); i++) {
        int x = A[i];
        while (!s.empty() && s.top() >= x) {
            s.pop();
        }
        if (s.empty()) {
            result.push_back(-1);
        } else {
            result.push_back(s.top());
        }
        s.push(x);
    }
    return result;
}
int main() {
	vector<int> A;
	A.push_back(4);
	A.push_back(5);
	A.push_back(2);
	A.push_back(10);
	A.push_back(8);
    vector<int> res = prevSmaller(A);
    cout << "Nearest smaller to the left: ";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

