#include <iostream>
using namespace std;

//5. toggle the ith bit

//Brute: convert to binary, if ith bit is 0, convert to 1 or vice versa, convert to decimal

//Optimal: shift left 1 to ith place, take xor with the number

int toggleIthBit(int n, int i){
    return (n ^ (1<<i));
}

int main(){
    cout<<toggleIthBit(9,2)<<endl;
    cout<<toggleIthBit(9,1)<<endl;
    return 0;
}