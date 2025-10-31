#include<iostream>
using namespace std;

//2. lower bound: smallest index such that arr[ind]>=x

//eg 
//[3,5,8,15,19]
//x=8, lb=2
//x=9, lb=3
//x=20, lb=5 (last hypothetical index)

//Brute: kind of like a linear search
//tc-> O(n)

//Optimal: we know that the search space is sorted. so, we can implement binary search
//tc-> O(logn) (base 2)

int lowerBound(vector<int>&arr, int x){
    int n=arr.size();
    int low=0, high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

//we also have lower_bound function in c++ stl
int lb(vector<int>&arr, int x){
    int lb=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
    return lb;
}

int main(){
    vector<int> v={1,2,3,3,7,8,9,9,9,11};
    int x=11;
    cout<<lowerBound(v,x)<<endl;
    cout<<lb(v,x)<<endl;
    return 0;
}