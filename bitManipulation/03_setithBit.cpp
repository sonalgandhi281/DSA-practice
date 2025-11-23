#include <iostream>
using namespace std;

//3. set the ith bit 

//eg: n=9, i=2
// convert 1001 to 1101

//Brute: convert to binary, change value of ith bit, convert back to decimal

//Optimal: shift left 1 by i bits, use OR operator

int setIthBit(int n, int i){
    return (n | (1<<i)); 
}

int main(){
    int n=9, i=2;
    cout<<setIthBit(n,i);
    return 0;
}