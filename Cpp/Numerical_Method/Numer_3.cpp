#include<iostream>
#include<cmath>
using namespace std;
//------------------ functions
double func(double x, int num, int n){
    return pow(num, n)-x;
}
double get_xM(double xL, double xR){
    return (xL+xR)/2;
}
string choseSide(double xM, double xR, int num, int n){
    return (func(xM, num, n)*func(xR, num, n)>0)? "xR":"xL";
}
double getErrorVal(){

}
double bisectionMethod(double xL, double xR){

}
//------------------ main
int main(){

}