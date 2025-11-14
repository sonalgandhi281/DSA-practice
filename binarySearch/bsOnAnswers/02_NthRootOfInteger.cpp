#include <iostream>
using namespace std;

//2. given 2 no.s N and M, find the Nth root of M. 
//x^N = M
//if Nth root is not an integer, return -1.

//Brute: linearly traverse from 1 to m, find nth power of each digit and return if it becomes equal to m.
//O(m*n) or O(mlogn) if we use binary exponentiation to calc power.

int nthRoot(int n,int m){
    for(int i=1;i<=m;i++){
        int val=1;
        for(int j=1;j<=n;j++){
            val*=i;
        }
        if(val==m) return i;
        if(val>m) break;
    }
    return -1;
}

//Optimal: we know that ans is possible till some values and then not possible. so, whenever we can find ways to eliminate search space, we can implement binary search.
//tc-> O(nlogm) ot O(logn * logm) if binary exponentiation

//return 1 if equal, 0 if less, 2 if greater
int powerN(int mid, int n, int m){
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans*=mid;
        if(ans>m) return 2;
    }
    if(ans==m) return 1;
    return 0;
}

int nthRootOptimal(int n, int m){
    int low=1, high=m;
    while(low<=high){
        int mid=(low+high)/2;
        int midN=powerN(mid,n,m);
        if(midN==1) return mid;
        else if(midN==0) low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int main(){
    int n=3, m=27;
    cout<<nthRoot(n,m)<<endl;
    cout<<nthRootOptimal(n,m);
    return 0;
}