#include <iostream>
using namespace std;

//8.a) Search element in a rotated sorted array [unique elements]

//eg
//[7,8,9,1,2,3,4,5,6], target=1
//ans=3

//Brute: linear search, tc-> O(n)

//Optimal: 
//since we see sorted and search, we are thinking of binary search.

//identify the sorted half (is it left or right) (by comparing low and high with mid value)

//then check for target in sorted half and eliminate halves accordingly

//tc-> O(logn), sc-> O(1)

int search1(vector<int> &arr, int target){
    int n=arr.size();
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target) return mid;
        if(arr[low]<=arr[mid]){
            if(arr[low]<=target && target<=arr[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else{
            if(arr[mid]<=target && target<=arr[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }
    return -1;
}

//b) Search element in a rotated sorted array [duplicate elements]
//we have to tell if it exists or not. we dont have to return index

//Brute: linear search, tc-> O(n)

//Optimal:

//think of edge case [3,1,2,3,3,3,3], low, mid, high all point to 3 so we cant find sorted and unsorted halves by this
//so prev approach wont work

//so, whenever we get condition arr[low]==arr[mid]==arr[high], we trim down / shrink our search space.

//tc-> O(logn) avg case, O(n/2) worst case in case u shrink almost half of array

bool search2(vector<int> &arr, int target){
    int n=arr.size();
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==target) return true;
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            low++;
            high--;
            continue;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low]<=target && target<=arr[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else{
            if(arr[mid]<=target && target<=arr[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
    }
    return false;
}


int main(){
    vector<int> v1={7,8,9,1,2,3,4,5,6};
    vector<int> v2={3,1,2,3,3,3};
    int x=1;
    cout<<search1(v1,x);
    cout<<endl;
    cout<<search2(v2,x);

    return 0;
}