#include<iostream>
using namespace std;
//------------------ functions
double func(double x){
    return (3*x)-5;
}
double checkErrorVal(double xM_Old, double xM_New){
    return abs((xM_New-xM_Old)/xM_New);
}
string chooseSide(double xM, double xR){
    return (func(xM)*func(xR)>0)? "xR":"xL";
}
double bisectionMethod(double xLIn, double xRIn){
    double xL=xLIn;
    double xR=xRIn;
    double errorVal;
    int n_iterations=0;
    do{
        double xM=(xL+xR)/2;
        string mySide=chooseSide(xM, xR);
        if(mySide=="xR"){
            xR=xM;
        }
        else if(mySide=="xL"){
            xL=xM;
        }
        errorVal=checkErrorVal(xM, (xL+xR)/2);
        n_iterations++;
    }
    while(errorVal>0.000001);
    cout<<"calculate time: "<<n_iterations<<endl;
    return (xL+xR)/2;
}
//------------------ main
int main(){
    cout<<bisectionMethod(-2, 2);
}