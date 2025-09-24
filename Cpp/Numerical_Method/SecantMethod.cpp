#include<iostream>
#include<cmath>
using namespace std;
//------------------ functions
double func(double x){
    return pow(x, 2)-7;
}
double checkError(double xNew, double xOld){
    return abs((xNew-xOld)/xNew);
}
double secantMethod(double x0, double x1){
    double errVal;
    double x2;
    do{
        x2=x1-((func(x1)*(x0-x1))/(func(x0)-func(x1)));
        errVal=checkError(x2, x1);
        x1=x2;
    }
    while(errVal>0.000001);
    return x2;
}
//------------------ main
int main(){
    cout<<secantMethod(2, 2.4);
}