#include<iostream>
using namespace std;
char bckArr[]={'_', '(', '[', '{', '<', ')', ']', '}', '>'};
//------------------ class
class Node{
	public:
		char ch;
		Node *next;
		Node(char chIn, Node *nodeIn){
			ch=chIn;
			next=nodeIn;
		}
};
class LinkedListStack{
	public:
        string stackStatus="normal";
		Node *head=NULL;
		void showLL(){
			for(Node *curr=head;curr!=NULL;curr=curr->next){
				cout<<curr->ch<<" ";
			}
			cout<<endl;
		}
		bool isEmpty(){
			return head==NULL;
		}
		void push(char newChar){
			head=new Node(newChar, head);
		}
		Node *pop(){
			Node *temp=NULL;
			if(head!=NULL){
				temp=head;
				head=head->next;
				temp->next=NULL;
			}
			return temp;
		}
};
class HashTable{
	public:
		LinkedListStack *ll[5];
		string bckStatus="/";
		int n_match=0;
		HashTable(){
			for(int i=0;i<5;i++){
				ll[i]=new LinkedListStack();
			}
		}
		int getIdx(char chIn){
			for(int i=1;i<=8;i++){
				if((chIn==bckArr[i])&&(i>4)){
					bckStatus="close";
					return i-4;	
				}
				else if((chIn==bckArr[i])&&(i<=4)){
					bckStatus="open";
					return i;
				}
			}
			return 0;
		}
		void addData(char chIn){
			int idx=getIdx(chIn);
			if(idx==0){
				return ;
			}
			if(bckStatus=="open"){
				ll[idx]->push(chIn);
			}
			else if(bckStatus=="close"){
				if(!ll[idx]->isEmpty()){
					n_match++;
					Node *temp=ll[idx]->pop();	
				}
				else if(ll[idx]->isEmpty()){
                    ll[idx]->stackStatus="errorEmpty";
				}
			}
		}
		void showTable(){
			for(int i=1;i<5;i++){
				if(ll[i]->head!=NULL){
					ll[i]->showLL();	
				}
				else{
					cout<<"NULL"<<endl;
				}
			}
		}
};
//------------------ functions
void mainFunc(string str){
	int strSize=str.length();
	HashTable *ht=new HashTable();
	for(int currIdx=0;currIdx<strSize;currIdx++){
        if(str[currIdx]==' '){
            continue;
        }
		if(((str[currIdx]=='<')&&(str[currIdx+1]=='<'))||((str[currIdx]=='>')&&(str[currIdx+1]=='>'))){
			currIdx++;
		}
		else{
            int stackIdx=ht->getIdx(str[currIdx]);
			if(stackIdx>0){
                ht->addData(str[currIdx]);
				if(ht->ll[stackIdx]->stackStatus=="errorEmpty"){
					break;
				}
			}
		}
	}
	for(int i=1;i<=4;i++){
		if((!ht->ll[i]->isEmpty())||(ht->ll[i]->stackStatus=="errorEmpty")){
			cout<<"Not matched"<<endl<<ht->n_match<<" matched"<<endl;
			return ;
		}
	}
	cout<<ht->n_match<<" matched"<<endl;
}
//------------------ main
int main(){
    string txt;
    getline (cin, txt);
	mainFunc(txt);
}