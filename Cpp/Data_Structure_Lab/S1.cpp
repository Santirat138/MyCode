#include <bits/stdc++.h> 
using namespace std;
int amount=0;
//------------------ class
class Node { 
	public: 
		int key; 
	 	Node* next; 
};
//------------------ functions
void insert(Node** head_ref, int new_key); 
void printList(Node* head); 
void insertAt(int post, Node** head_ref, int new_key); 
void remove(Node** head_ref, int key); 
void readNnumbers(Node** head_ref); 
void processCommand(char cmd, Node** head_ref); 
//------------------ main
int main() { 
	Node* head = NULL; 
	readNnumbers(&head);
	char command; 
	cin >> command; 
	while (command != 'q'){ 
  		processCommand(command, &head); 
  		cin >> command; 
 	}  
	return 0; 
} 
//------------------ functions
void readNnumbers(Node** head_ref){ 
	int n, key; 
	cin >> n;
	if(n>0 && n<20){
		amount=n;
		for (int i=0; i<n; i++){ 
			cin >> key;
			insert(head_ref, key);
		}
	} 
} 

void insert(Node** head_ref, int new_key){
    Node* new_node = new Node(); 
    new_node->key = new_key; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 
 
void printList(Node* head){
	if (head == NULL) cout << "empty\n"; 
  
    while (head) { 
        if (head->next == NULL) 
            cout << "[" << head->key << "] " << endl; 
        else 
            cout << "[" << head->key << "] "; 
        head = head->next; 
    } 
} 
void processCommand(char cmd, Node** head_ref){ 
	if (cmd == 'i'){ 
  		// *** Your code here! 
		int p, k;
		cin>>p>>k;
		insertAt(p, head_ref, k);
		printList(*head_ref);
	} 
	else if (cmd == 'd'){ 
  		// *** Your code here!
		int target;
		cin>>target;   
  		remove(head_ref, target);
		printList(*head_ref);
	} 
	
}
void insertAt(int post, Node** head_ref, int new_key){
	// *** Your code here!
	Node *currNode=*head_ref;
	Node *newNode=new Node();
	newNode->key=new_key;
	newNode->next=NULL;
	int walk=0;
	if((*head_ref==NULL)||(post==1)){
		amount++;
		insert(head_ref, new_key);
	}
	else if(post<=amount){
		while(currNode->next!=NULL){
			if(walk+2==post){		
				amount++;
				newNode->next=currNode->next;
				currNode->next=newNode;
				return ;
			}
			walk++;
			currNode=currNode->next;
		}
	}
	else if(post>amount){
		while(currNode->next!=NULL){
			currNode=currNode->next;
		}
		amount++;
		currNode->next=newNode;
	}	
}
void remove(Node** head_ref, int key){
	// *** Your code here!
    if((*head_ref==NULL)||(amount==0)){
        cout<<"empty"<<endl;
        return ;
    }
	if(key==(*head_ref)->key){
        amount--;
		Node *temp=*head_ref;
		(*head_ref)=(*head_ref)->next;
		temp->next=NULL;
	    cout<<key<<" deleted"<<endl;
		return ;
	} 
	for(Node *currNode=*head_ref;currNode->next!=NULL;currNode=currNode->next){
		if(currNode->next->key==key){
            amount--;
            Node *targNode=currNode->next;
			currNode->next=targNode->next;
			targNode->next=NULL;
            cout<<key<<" deleted"<<endl;
			return ;
		}
	}
	 cout<<key<<" not existed"<<endl;
}