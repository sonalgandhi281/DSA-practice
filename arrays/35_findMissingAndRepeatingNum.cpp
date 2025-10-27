#include<iostream>
using namespace std;

//35. find missing and repeating number
//given an array of n integers and values in range [1,n]. each integer appears exactly once except one which appears twice and one which is missing.

//Brute: loop from 1 to n and cnt for each num's occurence to find.

//TC-> O(n^2), SC-> O(1)

vector<int> missingRepeating(vector<int>&arr){
    int n=arr.size();
    int missing=-1, repeating=-1;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(arr[j]==i) cnt++;
        }
        if(cnt==2) repeating=i;
        else if(cnt==0) missing=i;

        if(repeating!=-1 && missing!=-1) break;
    }
    return {repeating,missing};
}

//Better: Hashing. we create hasharray from 0 to 6 (of size 7). initialize with 0. iterate and keep incrementing cnt accordingly. traverse hasharray and return repeating and missing no.

//TC-> O(2n), SC-> O(n)

vector<int> missingRepeatingBetter(vector<int>&arr){
    int n=arr.size();
    vector<int> hasharray(n+1,0);
    for(int i=0;i<n;i++){
        hasharray[arr[i]]++;
    }
    int repeating=-1, missing=-1;
    for(int i=1;i<=n;i++){
        if(hasharray[i]==2) repeating=i;
        else if(hasharray[i]==0) missing=i;

        if(repeating!=-1 && missing!=-1) break;
    }
    return {repeating,missing};
}

//Optimal soln 1: basic mathematics
//let x to be repeating no. and y to be missing no.
//sum up all elements of array called s
//find sum of n natural no.s called sn
//s-sn will give me x-y
//sum up all the squares and sum of squares of n natural no.s and subtract
//s2-s2n gives x^2-y^2

//so i get x-y and x+y, then i can find x and y.

//TC-> O(n), SC-> O(1)

vector<int> missingRepeatingOptimal1(vector<int>&arr){
    long long n=arr.size();
    long long SN=(n*(n+1))/2;
    long long S2N=(n*(n+1)*(2*n+1))/6;
    long long S=0, S2=0;
    for(int i=0;i<n;i++){
        S+=arr[i];
        S2+=(long long)arr[i]*(long long)arr[i];
    }
    int val1=S-SN; //x-y
    int val2=S2-S2N;
    val2=val2/val1; //x+y
    long long x= (val1+val2)/2;
    long long y=x-val1;
    return {(int)x,(int)y};
}

//Optimal2: xor method

int main(){
    vector<int> v={4,3,6,2,1,1};
    vector<int> ans1=missingRepeating(v);
    vector<int> ans2=missingRepeatingBetter(v);
    vector<int> ans3=missingRepeatingOptimal1(v);

    for(int x:ans1) cout<<x<<" ";
    cout<<endl;
    for(int x:ans2) cout<<x<<" ";
    cout<<endl;
    for(int x:ans3) cout<<x<<" ";

    return 0;
}
