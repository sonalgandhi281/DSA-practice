#include<iostream>
using namespace std;

//9. find the minimum element in a rotated sorted array

//Brute: linear search, tc-> O(n)

//Optimal: smallest element is point of rotation.
//tc-> O(logn) , sc-> O(1)

int findMin(vector<int> &arr){
    int n=arr.size();
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>arr[high]){
            low=mid+1;
        }else{
            high=mid;
        }
    }
    return arr[low];
}

int main(){
    vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    cout<<findMin(v)<<endl;
    return 0;
}