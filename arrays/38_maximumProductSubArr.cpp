#include<iostream>
using namespace std;

//38. Maximum Product Subarray

//Given an array that contains both negative and positive integers, find the maximum product subarray.

//Brute: generate all subarrays and calc product. track max product.

//TC-> O(n^3), SC-> O(1)

int maxProduct(vector<int>&arr){
    int n=arr.size();
    int maxP=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int prod=1;
            for(int k=i;k<=j;k++){
                prod*=arr[k];
            }
            maxP=max(maxP,prod);
        }
    }
    return maxP;
}

//Better: we reduce brute to 2 loops

//TC-> O(n^2), SC-> O(1)

int maxProductBetter(vector<int>&arr){
    int n=arr.size();
    int maxP=INT_MIN;
    for(int i=0;i<n;i++){
        int prod=1;
        for(int j=i;j<n;j++){
            prod*=arr[j];
            maxP=max(maxP,prod);
        }
    }
    return maxP;
}

//Optimal: 

//this problem has 2 optimal solns.
//one is observation based (soln is v intuitive), (mention this in interview!)

//second is an improvisation of kadane's algo (not intuitive, crammed soln), (not recommended to mention in interviews)

//Observation Based Approach:

// 1. if array has all +ves -> ans will be multiplication of all.

// 2. if even -ves and rest all +ves -> multiply everyone.

// 3. if odd -ves rest all +ves
// eg [3,2,-1,4,-6,3,-2,6]
// removal of one -ve out of odd -ves will give even -ves, so, we decide which -ve to remove
// after removing, we have either prefic mult or suffix mult
// i need to start from front, get prefix max, and start from back to get suffix max.

//4. if it has zeros, treat 0 as breaking point and treat elements before and after them as different subarrays. whenever pref=0, turn it back to 1 (starting off new)


//TC-> O(n), SC-> O(1)

int maxProductOptimal(vector<int>&arr){
    int n=arr.size();
    int maxP=INT_MIN;
    int pref=1, suff=1;
    for(int i=0;i<n;i++){
        if(pref==0) pref=1;
        if(suff==0) suff=1;
        pref*=arr[i];
        suff*=arr[n-1-i];
        maxP=max(maxP,max(pref,suff));
    }
    return maxP;
}

int main(){
    vector<int> v={2,3,-2,4};
    cout<<maxProduct(v)<<endl;
    cout<<maxProductBetter(v)<<endl;
    cout<<maxProductOptimal(v)<<endl;

    return 0;
}