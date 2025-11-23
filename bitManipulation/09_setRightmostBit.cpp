#include <iostream>
using namespace std;

//9. set the rightmost bit

//eg 1100 converts to 1101, 111 remains 111

//note that n+1 flips the rightmost unset bit to 1, and all bits to its right become 0
//so, n|n+1 will give ans

//tc-> O(1), sc-> O(1)

int setRightmostBit(int n){
    return (n | (n+1));
}

int main(){
    cout<<setRightmostBit(10);
    return 0;
}