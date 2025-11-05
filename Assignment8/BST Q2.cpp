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
    if (root == NULL) return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}
Node* searchRecursive(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}
Node* searchNonRecursive(Node* root, int key) {
    while (root != NULL) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}
Node* maximum(Node* root) {
    if (root == NULL) return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}
Node* minimum(Node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}
Node* inOrderSuccessor(Node* root, Node* node) {
    if (node->right != NULL)
        return minimum(node->right);
    Node* successor = NULL;
    Node* curr = root;
    while (curr != NULL) {
        if (node->data < curr->data) {
            successor = curr;
            curr = curr->left;
        } else if (node->data > curr->data)
            curr = curr->right;
        else
            break;
    }
    return successor;
}
Node* inOrderPredecessor(Node* root, Node* node) {
    if (node->left != NULL)
        return maximum(node->left);
    Node* predecessor = NULL;
    Node* curr = root;
    while (curr != NULL) {
        if (node->data > curr->data) {
            predecessor = curr;
            curr = curr->right;
        } else if (node->data < curr->data)
            curr = curr->left;
        else
            break;
    }
    return predecessor;
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
    int key = 15;
    Node* foundRec = searchRecursive(root, key);
    Node* foundNonRec = searchNonRecursive(root, key);
    cout << "Search " << key << " Recursive: " << (foundRec != NULL ? "Found" : "Not Found") << endl;
    cout << "Search " << key << " Non-Recursive: " << (foundNonRec != NULL ? "Found" : "Not Found") << endl;
    Node* maxNode = maximum(root);
    Node* minNode = minimum(root);
    cout << "Maximum element: " << (maxNode != NULL ? maxNode->data : -1) << endl;
    cout << "Minimum element: " << (minNode != NULL ? minNode->data : -1) << endl;
    Node* node = searchRecursive(root, 20);
    Node* succ = inOrderSuccessor(root, node);
    Node* pred = inOrderPredecessor(root, node);
    cout << "In-Order Successor of " << node->data << ": " << (succ != NULL ? succ->data : -1) << endl;
    cout << "In-Order Predecessor of " << node->data << ": " << (pred != NULL ? pred->data : -1) << endl;
    return 0;
}
