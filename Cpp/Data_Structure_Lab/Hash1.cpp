#include<iostream>
#define CAPACITY 17
using namespace std;
//------------------ class
class Node{
    public:
        int key;
        string data;
        Node *next;
        Node(int key, string data, Node *next){
            this->key=key;
            this->data=data;
            this->next=next;
        }
};
class LinkedList{
    public:
        Node *head=NULL;
        Node *addLast(Node *currNode, int key, string data){
            if(currNode==NULL){
                return new Node(key, data, NULL);
            }
            currNode->next=addLast(currNode->next, key, data);
            return currNode;
        }
        void showLL(){
            for(Node *curr=head;curr!=NULL;curr=curr->next){
                cout<<"("<<curr->key<<","<<curr->data<<") ";
            }
            cout<<endl;
        }
};
class HashTable{
    public:
        LinkedList *arrLL[CAPACITY];
        HashTable(){
            for(int idx=0;idx<CAPACITY;idx++){
                arrLL[idx]=new LinkedList();
            }
        }
        int getKey(int keyIn){
            return keyIn%CAPACITY;
        }
        void addData(int keyIn, string data){
            int key=getKey(keyIn);
            arrLL[key]->head=arrLL[key]->addLast(arrLL[key]->head, keyIn, data);
        }
        Node *findData(int keyIn){
            int key=getKey(keyIn);
            for(Node *curr=arrLL[key]->head;curr!=NULL;curr=curr->next){
                if(curr->key==keyIn){
                    return curr;
                }
            }
            return NULL;
        }
        void showData(){
            for(int currI=0;currI<CAPACITY;currI++){
                if(arrLL[currI]->head==NULL){
                    cout<<"(-1,-)"<<endl;
                }
                else{
                    arrLL[currI]->showLL();
                }
            }
        }
};
//------------------ functions
void mainFunc(){
    HashTable *ht=new HashTable();
    char ch;
    do{
        cin>>ch;
        if(ch=='a'){
            int key;
            string data;
            cin>>key;
            cin>>data;
            ht->addData(key, data);
        }
        else if(ch=='p'){
            ht->showData();
        }
        else if(ch=='s'){
            int keyIn;
            cin>>keyIn;
            Node *resultNode=ht->findData(keyIn);
            if(resultNode==NULL){
                cout<<"-"<<endl;
            }
            else{
                cout<<resultNode->data<<endl;
            }
        }
    }
    while(ch!='e');
}
//------------------ main
int main(){
    mainFunc();
}