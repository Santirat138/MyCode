#include<iostream>
using namespace std;

//------------------ functions
void showArray(int array[], int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
void mainFunc(int array[], int size){
    int lastIdx=size-1;
    int currIdx;
    for(currIdx=0;currIdx<lastIdx;currIdx++){
        if(array[currIdx]==0){
            if(array[lastIdx]==0){
                lastIdx--;
            }
            swap(array[currIdx], array[lastIdx--]);
        }
    }
}
//------------------ main
int main(){
    int array[]={1, 2, 0, 4, 3, 0, 5, 0};
    int size=sizeof(array)/sizeof(array[0]);
    mainFunc(array, size);
    showArray(array, size);
}