#include <iostream>
using namespace std;

//7. check if number is a power of 2

//note that a number that is a power of 2 will have only 1 set bit

//Brute: convert to binary and count set bits

//Optimal: if(n & n-1) is equal to 0, it is a power of 2

bool powerOf2(int n){
    return ((n&n-1) == 0);
}

int main(){
    cout<<powerOf2(16)<<endl;
    cout<<powerOf2(20)<<endl;
    return 0;
}