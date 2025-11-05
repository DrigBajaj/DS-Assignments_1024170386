#include <iostream>
using namespace std;
class Node {
	public:
	    int data;
	    Node* left;
	    Node* right;
	    Node(int value) {
	        data = value;
	        left = NULL;
	        right = NULL;
	    }
};
Node* insert(Node* root, int value) {
    if (root == NULL)
        return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}
Node* findMin(Node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return NULL;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}
int maxDepth(Node* root) {
    if (root == NULL) return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}
int minDepth(Node* root) {
    if (root == NULL) return 0;
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    if (root->left == NULL) return rightDepth + 1;
    if (root->right == NULL) return leftDepth + 1;
    return (leftDepth < rightDepth ? leftDepth : rightDepth) + 1;
}
void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main() {
    Node* root = NULL;
    int values[] = {20, 10, 30, 5, 15, 25, 35};
    for (int i = 0; i < 7; i++)
        root = insert(root, values[i]);
    cout << "BST In-Order Traversal: ";
    inOrder(root);
    cout << endl;
    int delKey = 10;
    root = deleteNode(root, delKey);
    cout << "BST after deleting " << delKey << ": ";
    inOrder(root);
    cout << endl;
    cout << "Maximum Depth of BST: " << maxDepth(root) << endl;
    cout << "Minimum Depth of BST: " << minDepth(root) << endl;
    return 0;
}
