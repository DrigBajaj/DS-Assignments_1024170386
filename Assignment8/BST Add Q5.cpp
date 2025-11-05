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
Node* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int& preIndex) {
    if (inStart > inEnd) return NULL;
    Node* root = new Node(preorder[preIndex]);
    preIndex++;
    if (inStart == inEnd) return root;
    int inIndex = findIndex(inorder, inStart, inEnd, root->val);
    root->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);
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
    int preorder[n], inorder[n];
    cout << "Enter preorder traversal: ";
    for (int i = 0; i < n; i++) cin >> preorder[i];
    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; i++) cin >> inorder[i];
    int preIndex = 0;
    Node* root = buildTree(preorder, inorder, 0, n - 1, preIndex);
    cout << "\nTree constructed successfully.\n";
    printTree(root);
    return 0;
}
