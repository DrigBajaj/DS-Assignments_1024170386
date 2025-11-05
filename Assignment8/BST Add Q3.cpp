#include <iostream>
#include <queue>
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
int maxDepth(Node* root) {
    if (root == NULL) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}
int main() {
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        cout << "\nTest case #" << t << endl;
        cout << "Enter number of nodes (including NULL nodes as -1): ";
        cin >> n;
        cout << "Enter " << n << " space-separated integers for level-order traversal (-1 for NULL):\n";
        Node* root = buildTree(n);
        int depth = maxDepth(root);
        cout << "Maximum depth of the binary tree: " << depth << endl;
    }
    return 0;
}
