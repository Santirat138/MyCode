#include<iostream>
using namespace std;
//------------------ class
class Node{
    public:
        int num;
        Node *left;
        Node *right;
        Node(int numIn, Node *nodeL, Node *nodeR){
            num=numIn;
            left=nodeL;
            right=nodeR;
        }
};
//------------------ functions
int getHeight(Node *targetNode){
    
}
void addNum(Node **rootRef, int newNum){
    if(*rootRef==NULL){
        *rootRef=new Node(newNum, NULL, NULL);
        return ;
    }
    if((*rootRef)->num<newNum){
        addNum(&((*rootRef)->right), newNum);
    }
    else if((*rootRef)->num>newNum){
        addNum(&((*rootRef)->left), newNum);
    }
}

void deleteNum(Node **currNodeRef, int targetNum){
    if((*currNodeRef)->num<targetNum){
        deleteNum(&((*currNodeRef)->right), targetNum);
    }
    else if((*currNodeRef)->num>targetNum){
        deleteNum(&((*currNodeRef)->left), targetNum);
    }
    else if((*currNodeRef)->num==targetNum){
        if(((*currNodeRef)->left==NULL)&&((*currNodeRef)->right==NULL)){
            *currNodeRef=NULL;
            return ;
        }
        else if((*currNodeRef)->left==NULL){
            *currNodeRef=(*currNodeRef)->right;
            return ;
        }
        else if((*currNodeRef)->right==NULL){
            *currNodeRef=(*currNodeRef)->left;
            return ;
        }
        else{

        }
    }
}
void showPreorder(Node *currNode){
    if(currNode!=NULL){
        cout<<currNode->num<<" ";
        showPreorder(currNode->left);
        showPreorder(currNode->right);
    }
}
void showInorder(Node *currNode){
    if(currNode!=NULL){
        showInorder(currNode->left);
        cout<<currNode->num<<" ";
        showInorder(currNode->right);
    }
}
void showPostorder(Node *currNode){
    if(currNode!=NULL){
        showPostorder(currNode->left);
        showPostorder(currNode->right);
        cout<<currNode->num<<" ";
    }
}
//------------------ main
int main(){
    Node *root=NULL;
    addNum(&root, 5);
    addNum(&root, 80);
    addNum(&root, 45);
    addNum(&root, 7);
    addNum(&root, 90);
    addNum(&root, 50);
    addNum(&root, 25);
    showPreorder(root);
}