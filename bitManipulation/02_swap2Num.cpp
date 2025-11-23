#include <iostream>
using namespace std;

//2. swap 2 numbers in place without using a third variable

void swapxor(int &a, int &b){
    a=a^b;
    b=a^b; //b=a^b^b=a
    a=a^b; //a=a^b^a=b
}

int main(){
    int a=6, b=7;
    cout<<a<<" "<<b<<endl;
    swapxor(a,b);
    cout<<a<<" "<<b<<endl;
    return 0;
}