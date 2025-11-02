#include<iostream>
using namespace std;

//7. count occurrencs of a no. in a sorted array

//Brute: linear search, increment counter whenever u find target
//tc-> O(n)

//Optimal: 
//total no. of occurrences = last occurrence - first occurrence + 1

//tc-> O(2*logn), sc-> O(1)


int first(vector<int> &arr, int x){
    int n=arr.size();
    int low=0, high=n-1;
    int f=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x){
            f=mid;
            high=mid-1;
        }else if(arr[mid]<x){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return f;
}

int last(vector<int> &arr, int x){
    int n=arr.size();
    int low=0, high=n-1;
    int l=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==x){
            l=mid;
            low=mid+1;
        }else if(arr[mid]<x){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return l;
}

pair<int,int> fl(vector<int>&arr, int x){
    int f=first(arr,x);
    int l=last(arr,x);
    return make_pair(f,l);
}

int countOccurrences(vector<int> &arr, int x){
    pair<int,int> ans=fl(arr,x);
    if(ans.first==-1) return 0;
    return (ans.second-ans.first+1);
}

int main(){
    vector<int> v={2,4,6,8,8,8,11,13};
    int x=8;
    cout<<countOccurrences(v,x);
    return 0;
}