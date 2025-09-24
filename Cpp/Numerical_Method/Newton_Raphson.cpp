#include<iostream>
#include<cmath>
using namespace std;
//------------------ functions
double func(double x){
    return pow(x, 2)-7;
}
double funcDiff(double x){
    return 2*x;
}
double findError(double xOld, double xNew){
    return abs((xNew-xOld)/xNew);
}
//------------------ main
int main(){
    double errVal;
    double x=2;
    double xNew;
    do{
        xNew=x-(func(x)/funcDiff(x));
        cout<<"F(x): "<<func(xNew)<<", x: "<<xNew<<endl;
        errVal=findError(x, xNew);
        x=xNew;
    }
    while(errVal>0.000001);
    cout<<x;
}