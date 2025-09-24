#include<iostream>
#include<cmath>
using namespace std;
//------------------ functions
double func(double x){
    return 13-pow(x, 4);
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
    }
    while(errorVal>0.000001);
    return (xL+xR)/2;
}
//------------------ main
int main(){
    cout<<"f(x) = "<<func(bisectionMethod(1.5, 2))<<", x = "<<bisectionMethod(1.5, 2);
}