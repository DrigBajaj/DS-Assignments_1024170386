#include <iostream>
using namespace std;
class SinglyLinkedList {
	private:
	    class Node {
	    public:
	        int data;
	        Node* next;
	        Node(int val) : data(val), next(NULL) {}
	    };
	    Node* head;
	public:
	    SinglyLinkedList() : head(NULL) {}
	    void insertAtEnd(int value) {
	        Node* newNode = new Node(value);
	        if (head == NULL) {
	            head = newNode;
	            return;
	        }
	        Node* temp = head;
	        while (temp->next != NULL)
	            temp = temp->next;
	        temp->next = newNode;
	    }
	    void display() {
	        if (head == NULL) {
	            cout << "List is empty.\n";
	            return;
	        }
	        Node* temp = head;
	        while (temp != NULL) {
	            cout << temp->data;
	            if (temp->next != NULL) cout << " -> ";
	            temp = temp->next;
	        }
	        cout << "\n";
	    }
	    int countAndDeleteKey(int key) {
	        int count = 0;
	        while (head != NULL && head->data == key) {
	            Node* temp = head;
	            head = head->next;
	            delete temp;
	            count++;
	        }
	        Node* current = head;
	        Node* prev = NULL;
	        while (current != NULL) {
	            if (current->data == key) {
	                Node* temp = current;
	                prev->next = current->next;
	                current = current->next;
	                delete temp;
	                count++;
	            } else {
	                prev = current;
	                current = current->next;
	            }
	        }
	        return count;
	    }
	    ~SinglyLinkedList() {
	        Node* current = head;
	        while (current != NULL) {
	            Node* temp = current;
	            current = current->next;
	            delete temp;
	        }
	    }
};
int main() {
    SinglyLinkedList list;
    int values[] = {1, 2, 1, 2, 1, 3, 1};
    for (int i = 0; i < 7; i++)
        list.insertAtEnd(values[i]);
    cout << "Original Linked List: ";
    list.display();
    int key = 1;
    int count = list.countAndDeleteKey(key);
    cout << "Count of key " << key << ": " << count << endl;
    cout << "Updated Linked List: ";
    list.display();
    return 0;
}
