#include<iostream>
using namespace std;

//6. find first or last occurrence of a given no. in a sorted array

//eg
//[2,4,6,8,8,8,11,13], x=8, ans=[3,4]; x=10, ans=[-1,-1]; x=6, ans=[6,6]

//naive soln: linearly traverse and when u find update values of first and last with appropriate index
//tc-> O(n)

vector<int> firstLast(vector<int>&arr, int x){
    int n=arr.size();
    int first=-1, last=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            if(first==-1) first=i;
            last=i;
        }
    }
    return {first,last};
}

//using binary search

//note that lower bound -> arr[ind]>=x and upper bound -> arr[ind]>x
//lb(8) will give index 3 and ub(8) will give index 5
//so, first=lb and last=ub-1

//but, if not present in array, like lb(10) it will give index 6. so, add condition to check

//tc-> O(2logn), sc-> O(1)

vector<int> firstLastOptimal(vector<int> &arr, int x){
    int n=arr.size();
    int lb=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
    int ub=upper_bound(arr.begin(),arr.end(),x)-arr.begin();
    if(lb==n || arr[lb]!=x) return {-1,-1};
    return {lb,ub-1};
}

//plain binary search approach (without lb and ub)

//we write separate binary search based algos to find first and last occurrence
//to find first, we search left
//to find last, we search right

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

int main(){
    vector<int> v={2,4,6,8,8,8,11,13};
    int x=8;
    vector<int> ans1=firstLast(v,x);
    vector<int> ans2=firstLastOptimal(v,x);
    pair<int,int> ans3=fl(v,x);

    for(int x:ans1) cout<<x<<" ";
    cout<<endl;
    for(int x:ans2) cout<<x<<" ";
    cout<<endl;
    cout<<ans3.first<<" "<<ans3.second;

    return 0;
}