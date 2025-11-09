#include<iostream>
using namespace std;

//10. find no, of times a sorted array has been rotated

//eg
//[4,5,1,2,3] has been rotated 2 times
//note that the index of minimum element in rotated sorted array gives us no. of rotations done on that array

//brute: linear search to find min element and its index O(n)

//optimal: based on binary search, we just find index of min element in rotated sorted array
//in a loop, find mid, find sorted half, compare leftmost element of sorted half with ans to get min, eliminate half accordingly

//tc->O(logn)

int noOfRotations(vector<int> &arr){
    int n=arr.size();
    int low=0, high=n-1;
    int ans=INT_MAX, index=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[low]<=arr[high]){
            if(arr[low]<=ans){
                ans=arr[low];
                index=low;
                break;
            }
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<ans){
                ans=arr[low];
                index=low;
                low=mid+1;
            }
        }
        else{
            if(arr[mid]<ans){
                ans=arr[mid];
                index=mid;
                high=mid-1;
            }
        }
    }
    return index;
}

int main(){
    vector<int> v={4,5,1,2,3};
    cout<<noOfRotations(v)<<endl;
    return 0;
}