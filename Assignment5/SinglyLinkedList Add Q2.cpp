#include <iostream>
using namespace std;
class Node {
	public:
	    int data;
	    Node* next;
	    Node(int val) : data(val), next(NULL) {}
};
class LinkedList {
	public:
	    Node* head;
	    LinkedList() : head(NULL) {}
	    void insertAtEnd(int val) {
	        Node* newNode = new Node(val);
	        if (head == NULL) {
	            head = newNode;
	            return;
	        }
	        Node* temp = head;
	        while (temp->next != NULL)
	            temp = temp->next;
	        temp->next = newNode;
	    }
	    Node* reverseKGroup(Node* start, int k, Node** nextGroupStart) {
	        Node* prev = NULL;
	        Node* curr = start;
	        Node* next = NULL;
	        int count = 0;
	        Node* check = start;
	        int nodeCount = 0;
	        while (check != NULL && nodeCount < k) {
	            check = check->next;
	            nodeCount++;
	        }
	        if (nodeCount < k) {
	            *nextGroupStart = NULL;
	            return start;
	        }
	        count = 0;
	        while (curr != NULL && count < k) {
	            next = curr->next;
	            curr->next = prev;
	            prev = curr;
	            curr = next;
	            count++;
	        }	
	    	*nextGroupStart = curr;
	        return prev;
	    }
	    void reverseInGroups(int k) {
	        if (head == NULL || k <= 1)
	            return;
	        Node* newHead = NULL;
	        Node* groupPrevTail = NULL;
	        Node* current = head;
	        while (current != NULL) {
	            Node* nextGroupStart = NULL;
	            Node* groupHead = reverseKGroup(current, k, &nextGroupStart);
	            if (newHead == NULL)
	                newHead = groupHead;
	            if (groupPrevTail != NULL)
	                groupPrevTail->next = groupHead;
	            groupPrevTail = current;
	            current = nextGroupStart;
	        }
	        head = newHead;
	    }
	    void display() {
	        Node* temp = head;
	        while (temp != NULL) {
	            cout << temp->data;
	            if (temp->next != NULL)
	                cout << " -> ";
	            temp = temp->next;
	        }
	        cout << "\n";
	    }
};
int main() {
    LinkedList list;
    int vals1[] = {1,2,3,4,5,6,7,8,9};
	for (int i = 0; i < sizeof(vals1)/sizeof(vals1[0]); i++)
    list.insertAtEnd(vals1[i]);
    cout << "Original List 1: ";
    list.display();
    list.reverseInGroups(3);
    cout << "Reversed in groups of 3: ";
    list.display();
    LinkedList list2;
    int vals2[] = {1,2,3,4,5,6,7,8};
    for (int i = 0; i < sizeof(vals2)/sizeof(vals2[0]); i++)
    list2.insertAtEnd(vals2[i]);
    cout << "\nOriginal List 2: ";
    list2.display();
    list2.reverseInGroups(3);
    cout << "Reversed in groups of 3: ";
    list2.display();
    return 0;
}
