#include<iostream>
using namespace std;
//------------------ class
class Node{
    public:
        string text;
        static int page;
        Node *prev;
        Node *next;
        Node(string textIn, Node *nodePrev, Node *nodeNext){
            text=textIn;
            prev=nodePrev;
            next=nodeNext;
        }
};
int Node::page=0;
class LinkedList{
    public:
        Node *head=NULL;
        Node *tail=NULL;
        void showLL(){
            for(Node *curr=head;curr!=NULL;curr=curr->next){
                cout<<curr->text<<" ";
            }
        }
        void addFirst(string textIn){
            head=new Node(textIn, NULL, head);
            Node::page++;
            cout<<Node::page<<endl;
        }
};
//------------------ main
int main(){
    LinkedList *ll=new LinkedList();
    ll->addFirst("aaa");
    ll->addFirst("bbb");
    ll->addFirst("ccc");
    ll->addFirst("ddd");
    ll->addFirst("eee");
    ll->showLL();
    
}