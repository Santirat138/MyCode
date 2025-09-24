#include<iostream>
using namespace std;
//------------------ class
class Stack{
    public:
        int top=0;
        int *array;
        Stack(int size){
            array=new int[size];
        }
        void push(int newNum){
            array[top++]=newNum;
        }
        int pop(){
            return (top<=0)? 0 : array[--top];
        }
};
//------------------ functions
bool mainFunc(string txt){
    int txtSize=txt.length();
    Stack stack(txtSize);
    for(int currI=0;currI<txtSize;currI++){
        if((txt[currI]=='(')||(txt[currI]==')')){
            if(txt[currI]=='('){
                stack.push(1);
            }
            else if(txt[currI]==')'){
                int temp=stack.pop();
                if(temp==0){
                    return false;
                }
            }
        }
    }
    if(stack.top==0){
        return true;
    }
    else{
        return false;
    }
}
//------------------ main
int main(){
    string txt;
    cin>>txt;
    if(mainFunc(txt)){
        cout<<"Pass"<<endl;
    }
    else{
        cout<<"Error"<<endl;
    }
}