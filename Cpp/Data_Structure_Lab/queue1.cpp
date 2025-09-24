#include<iostream>
using namespace std;
//------------------ class
class Queue{
    public:
        int front=0;
        int rear=0;
        int capacity;
        int size=0;
        int *array;
        Queue(int capacityIn){
            capacity=capacityIn;
            array=new int[capacity];
        }
        void enqueue(int newNum){
            if(rear<capacity){
                size++;
                array[rear++]=newNum;
            }
        }
        int dequeue(){
            if((rear>0)&&(front<rear)){
                size--;
                return array[front++];
            }
            return -1;
        }
        void showAll(){
            for(int currI=front;currI<rear;currI++){
                cout<<array[currI]<<" ";
            }
            cout<<endl;
        }
};
//------------------ functions
void mainFunc(){
    Queue queue(10);
    char ch;
    do{
        cin>>ch;
        if(ch=='e'){
            int newNum;
            cin>>newNum;
            queue.enqueue(newNum);
        }
        else if(ch=='d'){
            cout<<queue.dequeue()<<endl;
        }
        else if(ch=='p'){
            queue.showAll();
        }
        else if(ch=='n'){
            cout<<queue.size<<endl;
        }
        else if(ch=='s'){
            cout<<queue.array[queue.front]<<" "<<queue.array[queue.rear-1]<<endl;
        }
    }
    while(ch!='x');
}
//------------------ main
int main(){
    mainFunc();
}