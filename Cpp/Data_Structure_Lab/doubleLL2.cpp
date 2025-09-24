#include<iostream>
using namespace std;
//------------------ class
class Node{
    public:
        int num;
        Node *prev;
        Node *next;
        Node(int numIn, Node *nodePrev, Node *nodeNext){
            num=numIn;
            prev=nodePrev;
            next=nodeNext;
        }
};
//------------------ functions
class LinkedList{
    public:
        Node *head=NULL;
        Node *tail=NULL;
        void linkNode(Node *node1, Node *node2){
            node1->next=node2;
            node2->prev=node1;
        }
        void showLL(){
            Node *curr=head;
            while(curr!=tail){
                cout<<curr->num<<" ";
                curr=curr->next;
            }
            cout<<tail->num<<endl;
            while(curr!=head){
                cout<<curr->num<<" ";
                curr=curr->prev;
            }
            cout<<head->num<<endl<<endl;
        }
        void addFirst(int newNum){
            Node *newNode=new Node(newNum, NULL, NULL);
            if(head!=NULL){
                linkNode(newNode, head);
            }
            else{
                tail=newNode;
            }
            head=newNode;
        }
        void addLast(int newNum){
            Node *newNode=new Node(newNum, NULL, NULL);
            if(tail!=NULL){
                linkNode(tail, newNode);
            }
            else{
                head=newNode;
            }
            tail=newNode;
        }
        void deleteFirst(){
            Node *targetNode=head;
            head=head->next;
            targetNode->next=NULL;
            head->prev=NULL;
        }
        void deleteLast(){
            Node *targetNode=tail;
            tail=tail->prev;
            targetNode->prev=NULL;
            tail->next=NULL;
        }
};
//------------------ main
int main(){
    LinkedList *ll=new LinkedList();
    for(int num=1;num<=10;num++){
        ll->addLast(num);
    }
    ll->showLL();

    ll->addFirst(90);
    ll->addFirst(900);
    ll->showLL();

    ll->deleteFirst();
    ll->deleteLast();
    ll->showLL();
}