#include<iostream>
#define CAPACITY 5
using namespace std;
//------------------ class
class Index{
    public:
        int *ptrArray;
        int size;
        void showData(){
            for(int i=0;i<size;i++){
                cout<<*(ptrArray+i)<<" ";
            }
            cout<<endl;
        }
};
Index input[CAPACITY];
Index *ptrArray=input;
//------------------ functions
void showInputData(){
    for(int i=0;i<CAPACITY;i++){
        if((ptr+i)->ptrArray!=NULL){
            input[i].showData();
        }
        else{
            cout<<"NULL"<<endl;
        }
    }
}