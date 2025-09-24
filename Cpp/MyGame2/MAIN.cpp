#include "functions2.hpp"
#include "inputStorage.hpp"
int main(){
    Node *root=NULL;
    int array[]={76, 85, 86, 79, 78, 25, 62, 6, 1, 31};
    int size=sizeof(array)/sizeof(array[0]);
    createBST(&root);
    
    int ansArray[]={1, 2, 3};
    int ansSize=sizeof(ansArray)/sizeof(ansArray[0]);

    Index **pptrArray=&ptrArray;

    input[1].ptrArray=ansArray;
    input[1].size=ansSize;
    showInputData();
}