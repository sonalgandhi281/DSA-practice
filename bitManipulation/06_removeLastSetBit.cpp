#include <iostream>
using namespace std;

//6. remove/clear the last set bit (rightmost)

//Brute: convert to binary, traverse and check rightmost set bit and convert to 0, convert to decimal

//Optimal:
//eg n=16, means n is 10000, n-1 ie 15 will be 01111.
//notice that when we take n-1, rightmost set bit bcms 0 and all bits to right of it bcm 1.

//take & of n and n-1

int removeLastSet(int n){
    return (n & (n-1));
}

int main(){
    cout<<removeLastSet(16);
    return 0;
}