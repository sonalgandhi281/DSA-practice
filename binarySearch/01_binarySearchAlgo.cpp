#include <iostream>
using namespace std;

//Binary Search : a searching algo in a limited search space.
//Applicable whenever we are performing search on sorted data (done by splitting into half).

//1. Search a target in array by binary search
//TC-> O(logn) (base is 2)

//note: mid=(low+high)/2. but if search space is 0 to INT_MAX, what if during binary search mid=(2 x INT_MAX)/2. this will lead to overflow.
//so, we either use long long for low, high, or, we use formula mid=low+(high-low)/2.

//Iterative code

int binarySearchIterative(vector<int> &arr, int target){
    int n=arr.size();
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target) return mid;
        else if(target>arr[mid]) low=mid+1;
        else high=mid-1;
    }
    return -1;
}

//Recursive code

int binarySearchRecursive(vector<int> &arr, int low, int high, int target){
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(arr[mid]==target) return mid;
    else if(target>arr[mid]) return binarySearchRecursive(arr,mid+1,high,target);
    else return binarySearchRecursive(arr,low,mid-1,target);
}

int bs(vector<int> &arr, int target){
    return binarySearchRecursive(arr,0,arr.size()-1,target);
}

int main(){
    vector<int> v={3,4,6,7,9,12,16,17};
    int target=6;
    cout<<binarySearchIterative(v,target)<<endl;
    cout<<bs(v,target)<<endl;

    return 0;
}
