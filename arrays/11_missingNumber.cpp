#include <iostream>
using namespace std;

//11. Find missing number in an array : we are given N and an array of N-1 elements, which contains no.s from 1 to N. find missing no.

//Brute: loop from 1 to N, linear search in array for each element to find whats missing
//TC-> O(N^2), SC-> O(1)

int missingNumber(int N, vector<int> &arr){
    for(int i=1;i<=N;i++){
        int flag=0;
        for(int j=0;j<N-1;j++){
            if(arr[j]==i){
                flag=1;
                break;
            }
        }
        if(flag==0) return i;
    }
    return -1; //wont run ever if inputs are correct
}

//Better: Hashing. Create a hash array of size N+1. Traverse array and for each element in array, mark it as 1 in hash array. traverse hash array to find index where value is 0.
//TC-> O(2N), SC-> O(N)

int missingNumberBetter(int N, vector<int> &arr){
    vector<int> hash(N+1,0);
    for(int i=0;i<arr.size();i++){
        hash[arr[i]]=1;
    }
    for(int i=1;i<=N;i++){
        if(hash[i]==0){
            return i;
        }
    }
    return -1; //wont run ever if inputs are correct
}

//Optimal: 2 ways
//1. sum of N no.s is sum1=N*(N+1)/2. loop through array elements, add and store in sum2. missing no. = sum1-sum2.
//TC-> O(N), SC-> O(1)

int missingNumberOptimalSum(int N, vector<int>&arr){
    int sum1=0, sum2=0;
    sum1=N*(N+1)/2;
    for(int i=0;i<N-1;i++){
        sum2+=arr[i];
    }
    return sum1-sum2;
}

//2. xor1 = xor of 1 to N, xor = xor of array elements
//missing no. = xor1^xor2 
//TC-> O(N), SC-> O(1)

int missingNumberOptimalXor(int N, vector<int>&arr){
    int xor1=0, xor2=0;
    for(int i=0;i<N-1;i++){
        xor2^=arr[i];
        xor1^=(i+1);
    }
    xor1^=N;
    return xor1^xor2;
}

//Note: Xor approach is better than sum approach bcz, say N=10^5, then we have to compute N*(N+1), which cant be stored in int it will overflow. so we will need bigger memory space.

int main(){
    vector<int> a={1,2,3,5};
    cout<<missingNumber(5,a)<<endl;
    cout<<missingNumberBetter(5,a)<<endl;
    cout<<missingNumberOptimalSum(5,a)<<endl;
    cout<<missingNumberOptimalXor(5,a)<<endl;
    return 0;
}