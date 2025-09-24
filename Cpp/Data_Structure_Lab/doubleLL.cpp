#include<iostream>
using namespace std;
//------------------ class
class Node{
    public:
        int num;
        Node *prev;
        Node *next;
        Node(int numIn, Node *node1, Node *node2){
            num=numIn;
            prev=node1;
            next=node2;
        }
};
//------------------ functions
void linkNode(Node **node1, Node **node2){
    (*node1)->next=*node2;
    (*node2)->prev=*node1;
}

void addFirst(Node **headRef, int newNum){
    Node *newNode=new Node(newNum, NULL, NULL);
    if(*headRef!=NULL){
        linkNode(&newNode, headRef);
    }
    *headRef=newNode;
}
void addLast(Node **headRef, int newNum){
    if(*headRef==NULL){
        *headRef=new Node(newNum, NULL, NULL);
        return ;
    }
    for(Node *curr=*headRef;curr!=NULL;curr=curr->next){
        if(curr->next==NULL){
            Node *newNode=new Node(newNum, NULL, NULL);
            linkNode(&curr, &newNode);
            return ;
        }
    }

}
void deleteFirst(Node **headRef){
    Node *targetNode=*headRef;
    *headRef=(*headRef)->next;
    targetNode->next=NULL;
    (*headRef)->prev=NULL;
}
void deleteLast(Node **headRef){
    for(Node *curr=*headRef;curr!=NULL;curr=curr->next){
        if(curr->next->next==NULL){
            curr->next=NULL;
            return ;
        }
    }
}
void showLL(Node *head){
    Node *curr;
    for(curr=head;curr->next!=NULL;curr=curr->next){
        cout<<curr->num<<" ";
    }
    cout<<curr->num<<endl;
    while(curr!=NULL){
        cout<<curr->num<<" ";
        curr=curr->prev;
    }
    cout<<endl<<endl;
}
//------------------ main
int main(){
    Node *head=NULL;
    for(int num=1;num<=10;num++){
        addLast(&head, num);
    }
    showLL(head);
    deleteFirst(&head);
    showLL(head);
    deleteLast(&head);
    showLL(head);
    addFirst(&head, 800);
    showLL(head);
}