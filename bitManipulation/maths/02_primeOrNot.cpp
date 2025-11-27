#include <iostream>
using namespace std;

//2. check if a num is prime or not

//prime no. : a no. thats divisible by 1 and itself and no one else, and total no. of divisors is 2.

//Brute
//tc->O(n), sc->O(1)
bool primeNo(int n){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(n%i==0) cnt++;
    }
    if(cnt==2) return true;
    return false;
}

//Optimal
//tc-> O(sqrt(n)), sc->O(1)
bool prime(int n){
    for(int i=2;i*i<=n;i++){
        if((n%i)==0) return false;
    }
    return true;
}

int main(){
    cout<<primeNo(5)<<endl;
    cout<<prime(5)<<endl;
    cout<<primeNo(12)<<endl;
    cout<<prime(12)<<endl;
}