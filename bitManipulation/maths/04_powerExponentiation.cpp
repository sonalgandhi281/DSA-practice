#include <iostream>
using namespace std;

//4. given x and n, find x raised to power n

//Brute
//O(n)

int pow(int x, int n){
    int ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*x;
    }
    return ans;
}

//Optimal
//if power is even, i can reduce it by half, by squaring x. if power is odd, mult ans by x and make power even. keep repeating. in the end

//tc-> O(logn) base 2, bcz we keep reducing by half

double powOptimal(double x, int n){
    long long m=n;
    if(m<0) m=-1*m;
    double ans=1.0;
    while(m>0){
        if(m%2==1){
            ans=ans*x;
            m=m-1;
        }
        else{
            m=m/2;
            x=x*x;
        }
    }
    if(n<0) ans=(double)(1.0)/(double)(ans);//incase power was -ve
    return ans;
}

int main(){
    cout<<pow(2,5)<<endl;
    cout<<powOptimal(2,5)<<endl;
}