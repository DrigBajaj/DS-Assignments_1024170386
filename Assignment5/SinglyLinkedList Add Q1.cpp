#include <iostream>
using namespace std;
class Node {
	public:
	    int data;
	    Node* next;
	    Node(int val) : data(val), next(NULL) {}
};
int getLength(Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}
Node* getIntersectionNode(Node* headA, Node* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);
    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }
    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }
    while (headA != NULL && headB != NULL) {
        if (headA == headB) {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    Node* intersection = new Node(8);
    intersection->next = new Node(5);
    Node* headA = new Node(4);
    headA->next = new Node(1);
    headA->next->next = intersection;
    Node* headB = new Node(5);
    headB->next = new Node(6);
    headB->next->next = new Node(1);
    headB->next->next->next = intersection;
    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);
    Node* intersectNode = getIntersectionNode(headA, headB);
    if (intersectNode != NULL) {
        cout << "Intersected at node with value: " << intersectNode->data << endl;
    } else {
        cout << "No intersection found.\n";
    }
    return 0;
}
