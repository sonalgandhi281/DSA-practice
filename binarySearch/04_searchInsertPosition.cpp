#include<iostream>
using namespace std;

//4. search insert position

//given a sorted array of distinct values and target value 'm', search index of target value in array.

//if value is present, return index.

//else, determine the index where it should be inserted in the array while maintaining the sorted order.

//eg
//[1,2,4,7], m=6
//ans: 3

//soln: basically we have to implement lower bound

int searchInsert(vector<int>&arr, int m){
    int n=arr.size();
    int low=0, high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=m){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> v={1,2,4,7};
    int m=6;
    cout<<searchInsert(v,m)<<endl;

    return 0;
}