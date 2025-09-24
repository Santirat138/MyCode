#include<iostream>
#include<cmath>
using namespace std;
//------------------ variable
double errVal=0.000001;
int iterationLimit=100;
//------------------ class

//------------------ functions
bool errLimit(int iteration){
    return (iteration>=iterationLimit)? true:false;
}
double checkErr(double xOld, double xNew){
    return abs((xNew-xOld)/xNew);
}
double func(double x){
    return pow(x, 2)-2;
}
/* double diffFunc(double x){
    return ;
}
 */
double bisection(double xL, double xR){
    int iteration=0;
    double xM;
    do{
        iteration++;
        if(errLimit(iteration)){
            cout<<"Iteration limit."<<endl;
            return 0;
        }
        xM=(xL+xR)/2;
        cout<<endl<<"     I "<<iteration<<endl;
        int temp=func(xM)*func(xR);
        if(temp>0){
            cout<<"xR=xM"<<endl;
            xR=xM;
        }
        else{
            cout<<"XL=xM"<<endl;
            xL=xM;
        }
        errVal=checkErr(xM, (xL+xR)/2);
    }
    while(errVal>0.000001);
    cout<<"Bisection ("<<iteration<<"), ";
    return (xL+xR)/2;
}

/* double falsePosition(double xL, double xR){
    int iteration=0;
    double x1;
    do{
        iteration++;
        if(errLimit(iteration)){
            cout<<"Iteration limit."<<endl;
            return 0;
        }
        x1=((xL*func(xR)-xR*func(xL))/(func(xR)-func(xL)));
        double temp=func(x1)*func(xR);
        if(temp>0){
            xR=x1;
        }
        else{
            xL=x1;
        }
        errVal=checkErr(x1, (xL*func(xR)-xR*func(xL))/(func(xR)-func(xL)));
    }
    while(errVal>0.000001);
    cout<<"FalsePosition ("<<iteration<<"), ";
    return (xL*func(xR)-xR*func(xL))/(func(xR)-func(xL));
} */

/* double newtonRaphson(double x){
    int iteration=0;
    double xNew;
    do{
        iteration++;
        if(errLimit(iteration)){
            cout<<"Iteration limit."<<endl;
            return 0;
        }
        xNew=x-(func(x)/diffFunc(x));
        errVal=checkErr(x, xNew);
        x=xNew;
    }
    while(errVal>0.000001);
    cout<<"NewtonRaphson ("<<iteration<<"), ";
    return x-(func(x)/diffFunc(x));
} */
//------------------ main
int main(){
    cout<<bisection(1, 1.9)<<endl;
}