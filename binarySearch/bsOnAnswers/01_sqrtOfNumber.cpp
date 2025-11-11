#include<iostream>
using namespace std;

//1. find square root of a number. if n is not a perfect square, return floor value of sqrt(n).

//Brute: sqrt of n will lie bw 1 and n. linearly search to find largest integer x such that x*x<=n.
//O(n)

int sqrtNum(int n){
    int ans=0;
    for(int i=1;i<=n;i++){
        if((long long)i*i<=n) ans=i;
        else break;
    }
    return ans;
}

//Optimal: since our search space (1 to n) is sorted, we can apply binary search. for mid, check if its square is <= n, if yes, store in ans and check right. else, if square > n, check left.
//tc-> O(logn)

int sqrtNumOptimal(int n){
    int ans=0;
    int low=1, high=n;
    while(low<=high){
        long long mid=(low+high)/2;
        if(mid*mid<=n){
            ans=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}

int main(){
    cout<<sqrt(36)<<endl;//we can also use inbuilt fn
    cout<<sqrtNum(36)<<endl;
    cout<<sqrtNumOptimal(36)<<endl;
    return 0;
}