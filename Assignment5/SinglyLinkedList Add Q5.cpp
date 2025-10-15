#include <iostream>
using namespace std;
class Node{
	public:
	    int coeff,pow;
	    Node* next;
	    Node(int c,int p):coeff(c),pow(p),next(NULL){}
};
class Polynomial{
	public:
	    Node* head;
	    Polynomial():head(NULL){}
	    void insertTerm(int coeff,int pow){
	        Node* newNode=new Node(coeff,pow);
	        if(head==NULL){
	            head=newNode;
	            return;
	        }
	        Node* temp=head;
	        while(temp->next!=NULL)
	            temp=temp->next;
	        temp->next=newNode;
	    }
	    static Polynomial addPolynomials(Polynomial& p1,Polynomial& p2){
	        Polynomial result;
	        Node* t1=p1.head;
	        Node* t2=p2.head;
	        while(t1!=NULL&&t2!=NULL){
	            if(t1->pow==t2->pow){
	                int sumCoeff=t1->coeff+t2->coeff;
	                if(sumCoeff!=0)
	                    result.insertTerm(sumCoeff,t1->pow);
	                t1=t1->next;
	                t2=t2->next;
	            }
	            else if(t1->pow>t2->pow){
	                result.insertTerm(t1->coeff,t1->pow);
	                t1=t1->next;
	            }
	            else{
	                result.insertTerm(t2->coeff,t2->pow);
	                t2=t2->next;
	            }
	        }
	        while(t1!=NULL){
	            result.insertTerm(t1->coeff,t1->pow);
	            t1=t1->next;
	        }
	        while(t2!=NULL){
	            result.insertTerm(t2->coeff,t2->pow);
	            t2=t2->next;
	        }
	        return result;
	    }
	    void display(){
	        Node* temp=head;
	        while(temp!=NULL){
	            cout<<"["<<temp->coeff<<","<<temp->pow<<"]";
	            if(temp->next!=NULL)
	                cout<<",";
	            temp=temp->next;
	        }
	        cout<<"\n";
	    }
};
int main(){
    Polynomial p1,p2,sum;
    p1.insertTerm(5,2);
    p1.insertTerm(4,1);
    p1.insertTerm(2,0);
    p2.insertTerm(5,1);
    p2.insertTerm(5,0);
    cout<<"Polynomial 1: ";
    p1.display();
    cout<<"Polynomial 2: ";
    p2.display();
    sum=Polynomial::addPolynomials(p1,p2);
    cout<<"Sum: ";
    sum.display();
    return 0;
}

