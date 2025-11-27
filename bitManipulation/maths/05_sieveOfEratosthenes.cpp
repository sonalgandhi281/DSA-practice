#include <iostream>
using namespace std;

//given a number n, print all primes till n

//tc-> O(n+nlog(logn)+n), sc-> O(n)

int countprimes(int n){
    vector<int> prime(n+1);
    int cnt=0;
    for(int i=2;i<=n;i++){ //O(n)
        prime[i]=1;
    }
    for(int i=2;i<=n;i++){ //O(nlog(logn)) bcz its a prime harmonic series
        if(prime[i]==1){
            for(int j=i*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }
    for(int i=2;i<=n;i++){ //O(n)
        if(prime[i]==1) cnt++;
    }
    return cnt;
}

int main(){
    cout<<countprimes(11)<<endl;
}