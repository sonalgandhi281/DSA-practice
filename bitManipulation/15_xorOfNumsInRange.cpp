#include <iostream>
using namespace std;

//15. given an integer n, find xor of all numbers from 1 to n

//Brute: iterate from 1 to n and xor elements as u go
//tc-> O(n), sc-> O(1)

int xorRange(int n){
    int xorr=0;
    for(int i=1;i<=n;i++){
        xorr^=i;
    }
    return xorr;
}

//Optimal: we can notice pattern that if n%4==1 ans is 1, if n%4==2 ans is n+1, if n%4==3 ans is 0, n%4==0 ans is n.
//tc-> O(1), sc-> O(1)

int xorRangeOptimal(int n){
    if(n%4==1) return 1;
    else if(n%4==2) return n+1;
    else if(n%3==3) return 0;
    else return n;
}

//follow up ques
//what if we are given range from l to r, and we have to find xor of these elements

//Brute: loop from l to r and take xor, tc-> O(r-l+1), sc-> O(1)

//Optimal: find xor1 till l-1, find xor2 till r, take xor of both, that will be ans
//tc-> O(1), sc-> O(1)
int xorRange1(int l, int r){
    return xorRangeOptimal(l-1)^xorRangeOptimal(r);
}

int main(){
    cout<<xorRange(5)<<endl;
    cout<<xorRangeOptimal(5)<<endl;
    cout<<xorRange1(4,7);
    return 0;
}