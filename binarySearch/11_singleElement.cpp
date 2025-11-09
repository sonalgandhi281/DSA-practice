#include<iostream>
using namespace std;

//11. given a sorted array in which every element appears twice except one element, find the single element

//brute: loop and check for each element if same element appears either front or back, if not, its single element
//or, traverse and take xor of entire array
//O(n)

//optimal: array is sorted. we use binary search.
//note that on left of single element, pair is of (even,odd) indexes and on right of single element, pair is of (odd,even) indexes.
//so, we eliminate halves accordingly

//tc-> O(logn)

int singleElement(vector<int> &arr){
    int n=arr.size();
    if(n==1) return arr[0];
    if(arr[0]!=arr[1]) return arr[0];
    if(arr[n-1]!=arr[n-1]) return arr[n-1];
    int low=1, high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]!=arr[mid+1] && arr[mid]!=arr[mid-1]) return arr[mid];
        if((mid%2==0 && arr[mid]==arr[mid+1]) || (mid%2==1 && arr[mid]==arr[mid-1])) low=mid+1;
        else high=mid-1;
    }
    return -1; //just to avoid warning
}

int main(){
    vector<int> v={1,1,2,2,3,3,4,5,5,6,6};
    cout<<singleElement(v);
    return 0;
}