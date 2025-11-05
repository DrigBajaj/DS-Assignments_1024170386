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
class DLLNode {
	public:
	    int val;
	    DLLNode* prev;
	    DLLNode* next;
	    DLLNode(int value) {
	        val = value;
	        prev = NULL;
	        next = NULL;
	    }
};
Node* buildBST(int n) {
    if (n == 0) return NULL;
    int val;
    cin >> val;
    if (val == -1) return NULL;
    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);
    int count = 1;
    while (!q.empty() && count < n) {
        Node* curr = q.front();
        q.pop();
        cin >> val;
        count++;
        if (val != -1) {
            curr->left = new Node(val);
            q.push(curr->left);
        }
        if (count >= n) break;
        cin >> val;
        count++;
        if (val != -1) {
            curr->right = new Node(val);
            q.push(curr->right);
        }
    }
    return root;
}
void inorder(Node* root, int arr[], int& index) {
    if (root == NULL) return;
    inorder(root->left, arr, index);
    arr[index++] = root->val;
    inorder(root->right, arr, index);
}
int* mergeArrays(int arr1[], int n1, int arr2[], int n2, int& mergedSize) {
    int* merged = new int[n1 + n2];
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) merged[k++] = arr1[i++];
        else merged[k++] = arr2[j++];
    }
    while (i < n1) merged[k++] = arr1[i++];
    while (j < n2) merged[k++] = arr2[j++];
    mergedSize = k;
    return merged;
}
DLLNode* arrayToDLL(int arr[], int n) {
    if (n == 0) return NULL;
    DLLNode* head = new DLLNode(arr[0]);
    DLLNode* curr = head;
    for (int i = 1; i < n; i++) {
        DLLNode* temp = new DLLNode(arr[i]);
        curr->next = temp;
        temp->prev = curr;
        curr = temp;
    }
    return head;
}
void printDLL(DLLNode* head) {
    DLLNode* curr = head;
    while (curr != NULL) {
        cout << curr->val;
        if (curr->next != NULL) cout << " <-> ";
        curr = curr->next;
    }
    cout << " <-> null\n";
}
int main() {
    int n1, n2;
    cout << "Enter number of nodes in BST1 (including -1 for NULLs): ";
    cin >> n1;
    cout << "Enter BST1 nodes in level-order (-1 for NULL): ";
    Node* T1 = buildBST(n1);
    cout << "Enter number of nodes in BST2 (including -1 for NULLs): ";
    cin >> n2;
    cout << "Enter BST2 nodes in level-order (-1 for NULL): ";
    Node* T2 = buildBST(n2);
    int arr1[1000], arr2[1000], nArr1 = 0, nArr2 = 0;
    inorder(T1, arr1, nArr1);
    inorder(T2, arr2, nArr2);
    int mergedSize = 0;
    int* merged = mergeArrays(arr1, nArr1, arr2, nArr2, mergedSize);
    DLLNode* head = arrayToDLL(merged, mergedSize);
    cout << "\nMerged Doubly Linked List:\n";
    printDLL(head);
    delete[] merged;
    return 0;
}
