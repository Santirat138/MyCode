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
void addFirst(Node **headRef, Node **lastRef, int newNum){
    Node *newNode=new Node(newNum, *headRef);
    if(*headRef==NULL){
        *lastRef=newNode;
    }
    else{
        (*lastRef)->next=*headRef;
    }
    *headRef=newNode;
}
void addLast(Node **headRef, Node **lastRef, int newNum){
    Node *newNode=new Node(newNum, *headRef);
    if(*headRef==NULL){
        *headRef=newNode;
    }
    else{
        (*lastRef)->next=newNode;
    }
    *lastRef=newNode;
}
void deleteFirst(Node **headRef, Node **lastRef){
    Node *targetNode=*headRef;
    (*lastRef)->next=(*headRef)->next;
    *headRef=(*headRef)->next;
    targetNode->next=NULL;
}
void deleteLast(Node **headRef, Node **lastRef){
    for(Node *curr=*headRef;curr!=NULL;curr=curr->next){
        if(curr->next==*lastRef){
            Node *targetNode=*lastRef;
            curr->next=*headRef;
            *lastRef=curr;
            (*lastRef)->next=NULL;
            return ;
        }
    }
}
void showLL(Node *head, Node *last){
    for(Node *curr=head;curr!=last;curr=curr->next){
        cout<<curr->num<<" ";
    }
    cout<<last->num<<endl;
}
//------------------ main
int main(){
    Node *head=NULL;
    Node *last=NULL;
    for(int currNum=1;currNum<=10;currNum++){
        addLast(&head, &last, currNum);
    }
    showLL(head, last);
    deleteFirst(&head, &last);
    showLL(head, last);
    deleteLast(&head, &last);
    showLL(head, last);
    addFirst(&head, &last, 50);
    showLL(head, last);
}