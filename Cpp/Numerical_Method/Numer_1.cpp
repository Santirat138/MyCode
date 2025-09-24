#include<iostream>
#include<cmath>
using namespace std;
//------------------ function
double func(double xIn){
    return (43*xIn)-180;
}
double roughScan(double xIn){
    double xOld=xIn;
    while(func(xOld)*func(xOld+1)>0){
        xOld++;
    }
    return xOld;
}
double mainFunc(){
    double xL=roughScan(0);
    double xR=xL+1;
    for(double currX=xL;currX<xR;currX=currX+0.000001){
        cout<<"funcX: "<<func(currX)<<endl;
        if((func(currX)> -0.000001)&&(func(currX)<0.000001)){
            cout<<currX<<endl;
            return currX;
        }
    }
    return 0;
}
//------------------ main
int main(){
    cout<<mainFunc();
}