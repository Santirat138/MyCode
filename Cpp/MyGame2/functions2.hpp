#include "functions1.hpp"
#include "inputStorage.hpp"

int *ptrArr=input[0].ptrArray;
int arrSize=input[0].size;

void createBST(Node **root){
    for(int currI=0;currI<arrSize;currI++){
        insert(root, *(ptrArr+currI));
    }
}
void cmdBST(Node **root){
    cout<<"Preorder show"<<endl;
    cout<<"Inorder show"<<endl;
    cout<<"Postorder show"<<endl;
    cout<<"Delete number"<<endl;

}
