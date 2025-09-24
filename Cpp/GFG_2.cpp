#include<iostream>
#define CAPACITY 10
using namespace std;
//------------------ class
class Stack{
    public:
        int top=0;
        int array[CAPACITY];
        void push(int newNum){
            if(top<CAPACITY){
                array[top++]=newNum;
            }
        }
        int pop(){
            if(top>0){
                return array[--top];
            }
        }
};
//------------------ functions
void showArray(int array[], int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
void shiftRight(int array[], int size, int startIdx){
    Stack stack;
    int currIdx;
    for(currIdx=startIdx;currIdx<size;currIdx++){
        stack.push(array[currIdx]);
    }
    int trash=stack.pop();
    for(currIdx=size-1;currIdx>startIdx;currIdx--){
        array[currIdx]=stack.pop();
    }
}
void mainFunc(int array[], int size, int key){
    for(int currIdx=0;currIdx<size;currIdx++){
        if(array[currIdx]==key){
            shiftRight(array, size, currIdx);
            currIdx++;
        }
    }
}
//------------------ main
int main(){
	int array[]={0, 1, 2, 3, 0, 4, 0, 5, 6, 0};
	int size=sizeof(array)/sizeof(array[0]);
    int key=0;  // Output: {0, 0, 1, 2, 3, 0, 0, 4, 0, 0}
    mainFunc(array, size, key);
    showArray(array, size);
}