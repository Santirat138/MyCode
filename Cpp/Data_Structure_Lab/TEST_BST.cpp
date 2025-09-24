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
void addNum(int **rootRef, int newNum){

}
//------------------ main
int main(){
    Node *root=NULL;
    Node **rootRef=&root;

}