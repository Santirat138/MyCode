#include<iostream>
#define CAPACITY 10
#define ROOT 0
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
class MaxHeap{
	public:
		int array[CAPACITY];
		int lastIdx=0;
		void addNum(int newNum){
			array[lastIdx]=newNum;
			int currIdx=lastIdx;
			lastIdx++;
			int maxIdx;
			do{
				int parentIdx=getParentIdx(currIdx);
				int leftIdx=getLeftChildIdx(parentIdx);
				int rightIdx=getRightChildIdx(parentIdx);
				if(leftIdx>=lastIdx){
					return ;
				}
				if(rightIdx>=lastIdx){
					maxIdx=leftIdx;
				}
				else{
					if(array[leftIdx]>array[rightIdx]){
						maxIdx=array[leftIdx];
					}
					else{
						maxIdx=rightIdx;
					}
				}
				if(array[parentIdx]<array[maxIdx]){
					swap(array[parentIdx], array[maxIdx]);
				}
				currIdx--;
			}
			while(currIdx>=ROOT);
		}
		void deleteRoot(){
			array[ROOT]=array[lastIdx-1];
			lastIdx--;
			int currIdx=ROOT;
			int maxIdx;
			do{
				int leftIdx=getLeftChildIdx(currIdx);
				int rightIdx=getRightChildIdx(currIdx);
				if(leftIdx>=lastIdx){
					return ;
				}
				else if(rightIdx>=lastIdx){
					maxIdx=leftIdx;
				}
				else{
					if(array[leftIdx]>array[rightIdx]){
						maxIdx=leftIdx;
					}
					else{
						maxIdx=rightIdx;
					}
				}
				if(array[currIdx]<array[maxIdx]){
					swap(array[currIdx], array[maxIdx]);
					currIdx=maxIdx;
				}
				else{
					currIdx++;
				}
			}
			while(currIdx<lastIdx);

		}
		void showArray(){
			for(int currI=0;currI<lastIdx;currI++){
				cout<<array[currI]<<" ";
			}
			cout<<endl;
		}
};
//------------------ main
int main(){
	int lastIdx=0;
	MaxHeap maxHeap;
	maxHeap.addNum(5);
	maxHeap.addNum(4);
	maxHeap.addNum(9);
	maxHeap.addNum(7);
	maxHeap.addNum(3);
	maxHeap.addNum(1);
	maxHeap.addNum(6);
	maxHeap.showArray();
	// 9 7 6 4 3 1 5
	maxHeap.deleteRoot();
	maxHeap.showArray();
	// 7 5 6 4 3 1
}