#include <iostream>
using namespace std;
class Node{
	public:
	    int data;
	    Node* next;
	    Node(int val):data(val),next(NULL){}
};
class LinkedList{
	public:
	    Node* head;
	    LinkedList():head(NULL){}
	    void insertAtEnd(int val){
	        Node* newNode=new Node(val);
	        if(head==NULL){
	            head=newNode;
	            return;
	        }
	        Node* temp=head;
	        while(temp->next!=NULL) temp=temp->next;
	        temp->next=newNode;
	    }
	    Node* rotateLeft(int k){
	        if(head==NULL||k==0) return head;
	        Node* temp=head;
	        int length=1;
	        while(temp->next!=NULL){
	            temp=temp->next;
	            length++;
	        }
	        k=k%length;
	        if(k==0) return head;
	        temp->next=head;
	        Node* newTail=head;
	        for(int i=1;i<k;i++) newTail=newTail->next;
	        Node* newHead=newTail->next;
	        newTail->next=NULL;
	        head=newHead;
	        return head;
	    }
	    void display(){
	        Node* temp=head;
	        while(temp!=NULL){
	            cout<<temp->data;
	            if(temp->next!=NULL) cout<<" -> ";
	            temp=temp->next;
	        }
	        cout<<"\n";
	    }
};
int main(){
    LinkedList list;
    int values[]={1,2,3,4,5,6};
    for(int i=0;i<6;i++) list.insertAtEnd(values[i]);
    cout<<"Original List: ";
    list.display();
    int k=4;
    list.rotateLeft(k);
    cout<<"List after rotating left by "<<k<<": ";
    list.display();
    return 0;
}

