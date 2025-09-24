#include<iostream>
using namespace std;
//------------------ class
class Node{
    public:
        int num;
        Node *next;
        Node(int numIn, Node *nodeIn){
            num=numIn;
            next=nodeIn;
        }
};
//------------------ functions
void showLL(Node *head){
    for(Node *curr=head;curr!=NULL;curr=curr->next){
        cout<<curr->num<<" ";
    }
    cout<<endl;
}
void addLast(Node **headRef, int newNum){
    if(*headRef==NULL){
        *headRef=new Node(newNum, NULL);
        return ;
    }
    for(Node *curr=*headRef;curr!=NULL;curr=curr->next){
        if(curr->next==NULL){
            curr->next=new Node(newNum, NULL);
            break;
        }
    }
}

//------------------ main
int main(){
    Node *head=NULL;
    addLast(&head, 3);
    addLast(&head, 4);
    addLast(&head, 5);
    addLast(&head, 5);
    addLast(&head, 5);
    addLast(&head, 6);
    addLast(&head, 7);
    addLast(&head, 7);
    addLast(&head, 7);
    addLast(&head, 8);
    addLast(&head, 8);
    addLast(&head, 9);
    addLast(&head, 10);
    showLL(head);
    //
    showLL(head);
}