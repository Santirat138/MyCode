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
Node *findNum(Node *head, int numIn){
    for(Node *curr=head;curr!=NULL;curr=curr->next){
        if(curr->num==numIn){
            return curr;
        }
    }
    return NULL;
}
void addFirst(Node **headRef, int newNum){
    *headRef=new Node(newNum, *headRef);
}
void addLast(Node **headRef, int newNum){
    if(*headRef==NULL){
        *headRef=new Node(newNum, NULL);
    }
    else{
        addLast(&((*headRef)->next), newNum);
    }
}
void addBef(Node **headRef, int newNum, int targNum){
    Node *currNode;
    for(currNode=*headRef;currNode->next->num!=targNum;currNode=currNode->next){}
    currNode->next=new Node(newNum, currNode->next);
}
void addAft(Node **headRef, int newNum, int targNum){
    Node *targetNode=findNum(*headRef, targNum);
    targetNode->next=new Node(newNum, targetNode->next);
}
Node *deleteNum(Node **currNode, int targNum){
    if((*currNode)->num==targNum){
        return (*currNode)->next;
    }
    (*currNode)->next=deleteNum(&((*currNode)->next), targNum);
    return *currNode;
}

//------------------ main
int main(){
    Node *head=NULL;
    Node **headRef=&head;

    addLast(headRef, 1);
    addLast(headRef, 2);
    addLast(headRef, 3);
    addLast(headRef, 4);
    addLast(headRef, 5);
    *headRef=deleteNum(headRef, 1);
    showLL(head);
}