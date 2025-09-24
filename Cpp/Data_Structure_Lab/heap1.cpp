#include<iostream>
#define SIZE 20
using namespace std;
//------------------ functions
int getParentIdx(int idx){
    return (idx-1)/2;
}
int getLeftChildIdx(int idx){
    return (2*idx)+1;
}
int getRightChildIdx(int idx){
    return (2*idx)+2;
}
//------------------ class
class Heap{
	public:
		int array[SIZE];
		int root=0;
		int lastIdx=0;
		void showArray(){
			for(int currI=0;currI<=lastIdx;currI++){
				cout<<array[currI]<<" ";
			}
			cout<<endl;
		}
		void addNum(int newNum){
			array[++(lastIdx)]=newNum;
			int currIdx=lastIdx;
			while(currIdx>0){
				int parentIdx=getParentIdx(currIdx);
				if(array[parentIdx]<array[currIdx]){
					swap(array[parentIdx], array[currIdx]);
					currIdx=parentIdx;
				}
				else{
					break;
				}
			}
		}
		int deleteRoot(int *lastIdx){
			if(*lastIdx<0){
				return -1;
			}
			int temp=array[0];
			if(*lastIdx>0){
				array[0]=array[(*lastIdx)--];
			}
			else{
				return -1;
			}
			int currIdx=0;
			while(currIdx<=*lastIdx){
				int lChild=getLeftChildIdx(currIdx);
				int rChild=getRightChildIdx(currIdx);
				if(lChild>*lastIdx){
					return temp;
				}
				else if((rChild>*lastIdx)&&(array[currIdx]<array[lChild])){
					swap(array[currIdx], array[lChild]);
					currIdx=lChild;
					return temp;
				}
				if((array[lChild]<array[rChild])&&(array[currIdx]<array[rChild])){
					swap(array[currIdx], array[rChild]);
					currIdx=rChild;
				}
				else if((array[lChild]==array[rChild])||(array[lChild]>array[rChild])&&(array[currIdx]<array[lChild])){
					swap(array[currIdx], array[lChild]);
					currIdx=lChild;
				}
			}
			return temp;
		}
};


void mainFunc(){
	Heap heap;
	char chIn;
	do{
		cin>>chIn;
		if(chIn=='a'){
			int newNum;
			cin>>newNum;
			heap.addNum(newNum);
		}
		else if(chIn=='d'){
			cout<<heap.deleteRoot(&(heap.lastIdx))<<endl;
		}
		else if(chIn=='p'){
			if(heap.lastIdx>=0){
				heap.showArray();
			}
		}
	}
	while(chIn!='e');
}
//------------------ main
int main(){
	mainFunc();
}