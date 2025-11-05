#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Node {
	public:
	    int val;
	    Node* left;
	    Node* right;
	    Node(int value) {
	        val = value;
	        left = NULL;
	        right = NULL;
	    }
};
Node* buildTree(int n) {
    if (n == 0) return NULL;
    int value;
    cin >> value;
    if (value == -1) return NULL;
    Node* root = new Node(value);
    queue<Node*> q;
    q.push(root);
    int count = 1;
    while (!q.empty() && count < n) {
        Node* curr = q.front();
        q.pop();
        if (count < n) {
            cin >> value;
            count++;
            if (value != -1) {
                curr->left = new Node(value);
                q.push(curr->left);
            }
        }
        if (count < n) {
            cin >> value;
            count++;
            if (value != -1) {
                curr->right = new Node(value);
                q.push(curr->right);
            }
        }
    }
    return root;
}
vector<int> rightView(Node* root) {
    vector<int> view;
    if (root == NULL) return view;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        Node* last = NULL;
        for (int i = 0; i < sz; i++) {
            Node* curr = q.front();
            q.pop();
            last = curr;
            if (curr->left != NULL) q.push(curr->left);
            if (curr->right != NULL) q.push(curr->right);
        }
        if (last != NULL) view.push_back(last->val);
    }
    return view;
}
int main() {
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        cout << "\nTest case #" << t << endl;
        cout << "Enter number of nodes (including NULL as -1): ";
        cin >> n;
        cout << "Enter " << n << " space-separated integers for level-order (-1 = NULL):\n";
        Node* root = buildTree(n);
        vector<int> view = rightView(root);
        cout << "Right view of the binary tree: ";
        for (int i = 0; i < view.size(); i++) {
            cout << view[i];
            if (i != view.size() - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
