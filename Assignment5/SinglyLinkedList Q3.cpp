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
    void printMiddle() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast == NULL) {
            Node* prev = head;
            while (prev->next != slow)
                prev = prev->next;
            cout << "Middle nodes are: " << prev->data << " and " << slow->data << endl;
        } else {
            cout << "Middle node is: " << slow->data << endl;
        }
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
    int values1[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; i++)
        list.insertAtEnd(values1[i]);
    cout << "Linked List: ";
    list.display();
    list.printMiddle();
    SinglyLinkedList list2;
    int values2[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
        list2.insertAtEnd(values2[i]);
    cout << "\nLinked List: ";
    list2.display();
    list2.printMiddle();
    return 0;
}
