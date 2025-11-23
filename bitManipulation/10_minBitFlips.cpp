#include <iostream>
using namespace std;

//10. return minimum bit flips required to turn start number to goal number

//eg start=10, goal=7
//1010 to 0111, ans=3

//take xor of start and goal, it will give 1 at bit indexes if bits are different. then count set bits.

int minBitFlips(int start, int goal){
    int num=start^goal;
    int cnt=0;
    for(int i=0;i<32;i++){
        cnt+=(num&1);
        num>>=1;
    }
    return cnt;
}

int main(){
    cout<<minBitFlips(10,7);
    return 0;
}