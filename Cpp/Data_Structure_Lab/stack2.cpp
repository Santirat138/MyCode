#include<iostream>
#define CAPACITY 10
using namespace std;
//------------------ class
class Stack{
    public:
        int array[CAPACITY];
        int top=0;
        void push(int newNum){
            array[top++]=newNum;
        }
        int pop(){
            return (top>0)? array[--top] : -1;
        }
};
//------------------ functions
void showArray(int array[], int size){
    for(int currI=0;currI<size;currI++){
        cout<<array[currI]<<" ";
    }
    cout<<endl;
}
void mainFunc(){
    Stack stack;
    char ch;
    do{
        cin>>ch;
        if(ch=='U'){
            int newNum;
            cin>>newNum;
            stack.push(newNum);
        }
        else if(ch=='O'){
            if(stack.top<=0){
                cout<<"-1"<<endl;
            }
            else{
                cout<<stack.pop()<<endl;
            }
        }
        else if(ch=='T'){
            cout<<stack.array[stack.top-1]<<endl;
        }
        else if(ch=='P'){
            showArray(stack.array, stack.top);
        }
        else if(ch=='N'){
            cout<<stack.top<<endl;
        }
    }
    while(ch!='X');
}
//------------------ main
int main(){
    mainFunc();
}