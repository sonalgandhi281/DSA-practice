#include <iostream>
using namespace std;

//4. clear the ith bit (if its 1, change to 0, if its 0, keep it as 0)

//eg n=13, i=2
//convert 1101 to 1001

//Brute: convert to binary, change ith place accordingly, convert to decimal

//Optimal: i want to place 0 at ith place and 1 at all other places, and take & with the number
//first, place 1 on ith bit and 0 everywhere else (1<<i), then do a negation (not operator) on it.

int clearIthBit(int n, int i){
    return (n & ~(1<<i));
}

int main(){
    int n=13, i=2;
    cout<<clearIthBit(n,i);
    return 0;
}