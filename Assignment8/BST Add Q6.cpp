#include <iostream>
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
int findIndex(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}
Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int& postIndex) {
    if (inStart > inEnd) return NULL;
    Node* root = new Node(postorder[postIndex]);
    postIndex--;
    if (inStart == inEnd) return root;
    int inIndex = findIndex(inorder, inStart, inEnd, root->val);
    root->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);
    root->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);
    return root;
}
void printTree(Node* root, int space = 0, int indent = 5) {
    if (root == NULL) return;
    space += indent;
    printTree(root->right, space);
    cout << endl;
    for (int i = indent; i < space; i++) cout << " ";
    cout << root->val << "\n";
    printTree(root->left, space);
}
int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    int inorder[n], postorder[n];
    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; i++) cin >> inorder[i];
    cout << "Enter postorder traversal: ";
    for (int i = 0; i < n; i++) cin >> postorder[i];
    int postIndex = n - 1;
    Node* root = buildTree(inorder, postorder, 0, n - 1, postIndex);
    cout << "\nTree constructed successfully.\n";
    printTree(root);
    return 0;
}
