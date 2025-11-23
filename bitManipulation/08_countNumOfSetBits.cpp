#include <iostream>
using namespace std;

//8. count the number of set bits

//Brute: convert to binary, traverse abd count set bits
//tc-> O(logn)

//note instead of checking n%2==1, i can do n&1 == 1, bcz last bit of odd no. will always be 1. and n&1 returns 0 if even, 1 if odd.
//also, instead of n/=2, we can use right shift operator

//bitwise operations are slightly faster than other operations that is why in cp most people use them

//in c++, there is inbuilt fn to count set bits
//__builtin_popcount(n)

int countSetBits(int n){
    int cnt=0;
    while(n>0){
        cnt+=(n&1);
        n=n>>1;
    }
    return cnt;
}

//Optimal: turn off the rightmost set bit by doing n&n-1, increment count, keep doing until n becomes 0
//tc-> O(no. of set bits), sc-> O(1)

int countSetBitsOptimal(int n){
    int cnt=0;
    while(n){
        n&=(n-1);
        cnt++;
    }
    return cnt;
}

int main(){
    cout<<countSetBits(9)<<endl;
    cout<<countSetBitsOptimal(9)<<endl;
}