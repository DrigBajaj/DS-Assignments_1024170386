#include <iostream>
using namespace std;
class Node {
	public:
	    int data;
	    Node* next;
	
	    Node(int val) {
	        data = val;
	        next = NULL;
	    }
};
bool isCircular(Node* head) {
    if (head == NULL) return false;
    Node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
    return (temp == head);
}
Node* createLinkedList(int arr[], int n) {
    if (n == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for (int i = 1; i < n; i++) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}
int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter node values separated by spaces: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Node* head = createLinkedList(arr, n);
    //Uncomment to make linked list circular
    /*Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = head;*/
    if (isCircular(head)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    delete[] arr;
    return 0;
}
