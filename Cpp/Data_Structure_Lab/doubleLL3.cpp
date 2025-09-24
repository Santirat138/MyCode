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

}
void addLast(Node **headRef, int newNum){

}
void deleteFirst(Node **headRef){

}
void deleteLast(Node **headRef){

}
void showLL(Node *head, Node *tail){
    for(Node *curr=head;curr!=NULL;curr=curr->next){
        cout<<curr->num<<" ";
    }
    cout<<endl;
    for(Node *curr=tail;curr!=NULL;curr=curr->prev){
        cout<<curr->num<<" ";
    }
    cout<<endl<<endl;
}
//------------------ main
int main(){
    Node *head=NULL;
    Node *tail=NULL;

}