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
Node *getPrevNode(Node *head, int targNum){
    for(Node *curr=head;curr!=NULL;curr=curr->next){
        if(curr->next->num==targNum){
            return curr;
        }
    }
    return NULL;
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
void addBef(Node **headRef, int newNum, int targNum){
    Node *targNode=findNum(*headRef, targNum);
    if(targNode==*headRef){
        *headRef=new Node(newNum, *headRef);
        return ;
    }
    if((targNode!=NULL)&&(newNum!=targNum)){
        Node *newNode=new Node(newNum, targNode);
        Node *prevNode=getPrevNode(*headRef, targNum);
        prevNode->next=newNode;
    }
    else{
        addLast(headRef, newNum);
    }
}
void addAft(Node **headRef, int newNum, int targNum){
    if(*headRef==NULL){
        *headRef=new Node(newNum, NULL);
        return ;
    }
    for(Node *currNode=*headRef;currNode!=NULL;currNode=currNode->next){
        if(currNode->num==targNum){
            currNode->next=new Node(newNum, currNode->next);
            return ;
        }
    }
    addLast(headRef, newNum);
}
void deleteNum(Node **headRef, int targNum){
    if((targNum==(*headRef)->num)&&((*headRef)->next!=NULL)){
        Node *temp=*headRef;
        *headRef=(*headRef)->next;
        temp->next=NULL;
        return ;
    }
    for(Node *curr=*headRef;curr->next!=NULL;curr=curr->next){
        if(curr->next->num==targNum){
            Node *temp=curr->next;
            curr->next=temp->next;
            temp->next=NULL;
            return ;
        }
    }
}
void mainFunc(Node **headRef){
    char ch;
    do{
        cin>>ch;
        if(ch=='A'){
            int newNum, targNum;
            cin>>newNum;
            cin>>targNum;
            if(findNum(*headRef, newNum)==NULL){
                addAft(headRef, newNum, targNum);
                showLL(*headRef);
            }
        }
        else if(ch=='I'){
            int newNum, targNum;
            cin>>newNum;
            cin>>targNum;
            if(findNum(*headRef, newNum)==NULL){
                addBef(headRef, newNum, targNum);
                showLL(*headRef);
            }
        }
        else if(ch=='D'){
            int targNum;
            cin>>targNum;
            if(findNum(*headRef, targNum)!=NULL){
                deleteNum(headRef, targNum);
                showLL(*headRef);
            }
        }
    }
    while(ch!='E');
}
//------------------ main
int main(){
    Node *head=NULL;
    mainFunc(&head);
}