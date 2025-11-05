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
bool isBST(Node* root, Node* minNode = NULL, Node* maxNode = NULL) {
    if (root == NULL) return true;
    if ((minNode != NULL && root->data <= minNode->data) ||
        (maxNode != NULL && root->data >= maxNode->data))
        return false;
    return isBST(root->left, minNode, root) &&
           isBST(root->right, root, maxNode);
}
void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main() {
    Node* root1 = new Node(20);
    root1->left = new Node(10);
    root1->right = new Node(30);
    root1->left->left = new Node(5);
    root1->left->right = new Node(15);
    root1->right->left = new Node(25);
    root1->right->right = new Node(35);
    cout << "In-Order Traversal of Tree 1: ";
    inOrder(root1);
    cout << endl;
    if (isBST(root1))
        cout << "Tree 1 is a BST" << endl;
    else
        cout << "Tree 1 is NOT a BST" << endl;
    Node* root2 = new Node(20);
    root2->left = new Node(30);
    root2->right = new Node(10);
    cout << "In-Order Traversal of Tree 2: ";
    inOrder(root2);
    cout << endl;
    if (isBST(root2))
        cout << "Tree 2 is a BST" << endl;
    else
        cout << "Tree 2 is NOT a BST" << endl;
    return 0;
}
