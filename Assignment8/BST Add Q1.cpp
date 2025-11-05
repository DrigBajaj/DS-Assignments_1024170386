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
bool isLeaf(Node* node) {
    return (node != NULL && node->left == NULL && node->right == NULL);
}
int sumOfLeftLeaves(Node* root) {
    if (root == NULL) return 0;
    int sum = 0;
    if (root->left != NULL && isLeaf(root->left))
        sum += root->left->data;
    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);
    return sum;
}
int main() {
    /*
        Example tree:
                3
               / \
              9  20
                 /  \
                15   7
    */
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    int sum = sumOfLeftLeaves(root);
    cout << "Sum of left leaves: " << sum << endl;
    return 0;
}
