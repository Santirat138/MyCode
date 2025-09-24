#include <iostream>
using namespace std;
//------------------ class
class Node{
	public:
		int data;
		Node* left;
		Node* right;
		
		Node(int d){
			data = d;
			left = NULL;
			right = NULL;
		}	
};
//------------------ functions
int addChild(Node* parent, Node*child){
	if (parent->left == NULL) {
		parent->left = child;
		return 1;
	}
	else if (parent->right == NULL){
		parent->right = child;
		return 2;
	}
	return 0; // CANNOT add a child
}

void printPostorder(Node* node)
{
    if (node == NULL)
        return;

    // First recur on left subtree
    printPostorder(node->left);

    // Then recur on right subtree
    printPostorder(node->right);
    
    // Now deal with the node
    cout << node->data << " ";
}
//------------------ main
int main(){
	int N,x,parent=0;
	cin>> N;
	Node* nodes[N];
	// Queue for parent!!!
	// enqueue(newnode)
	// first of queue -> parent for a newnode (left or right)
	cin >> x;
	nodes[0] = new Node(x); // root has no parent
	for (int i=1; i<N; i++){
		cin >> x;
		nodes[i] = new Node(x);
		int c = addChild(nodes[parent], nodes[i]);
		if (c==2) parent++;
	}
	
	cout << "\nInorder: ";
	printPostorder(nodes[0]);
	cout << "\nPreorder: ";
	printPostorder(nodes[0]);
	cout << "\nPostorder: ";
	printPostorder(nodes[0]);

	return 0;
}
