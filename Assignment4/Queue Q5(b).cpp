#include <iostream>
#include <queue>
using namespace std;
class StackOneQueue {
    queue<int> q;
	public:
	    void push(int x) {
	        q.push(x);
	        int sz = q.size();
	        for (int i = 0; i < sz - 1; i++) {
	            q.push(q.front());
	            q.pop();
	        }
	    }
	    int pop() {
	        if (q.empty()) {
	            cout << "Stack is empty\n";
	            return -1;
	        }
	        int top = q.front();
	        q.pop();
	        return top;
	    }
	    int top() {
	        if (q.empty()) {
	            cout << "Stack is empty\n";
	            return -1;
	        }
	        return q.front();
	    }
	    bool empty() {
	        return q.empty();
	    }
};
int main() {
    StackOneQueue s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.top() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;
    s.push(40);
    cout << "Top element: " << s.top() << endl;
    return 0;
}

