#include <iostream>
using namespace std;

//11. painter's partition problem

// Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint. You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards under the constraint that any painter will only paint the continuous sections of boards.

//SAME AS SPLIT ARRAY - LARGEST SUM PROBLEM
int countPart(vector<int> &arr, int maxSum){
    int n=arr.size();
    int painter=1, sum=0;
    for(int i=0;i<n;i++){
        if(sum+arr[i] <= maxSum){
            sum+=arr[i];
        }else{
            painter++;
            sum=arr[i];
        }
    }
    return painter;
}

//Brute:
//O(n * (sum-max+1))
int painterPart(vector<int> &arr, int k){
    int maxi=*max_element(arr.begin(),arr.end());
    int sum=0;
    for(int x:arr)sum+=x;
    for(int i=maxi;i<=sum;i++){
        if(countPart(arr,i)==k) return i;
    }
    return sum;
}

//Optimal:
//O(n * log(sum-max+1))
int painterPartOptimal(vector<int> &arr, int k){
    int low=*max_element(arr.begin(),arr.end());
    int high=0;
    for(int x:arr)high+=x;
    while(low<=high){
        int mid=(low+high)/2;
        if(countPart(arr,mid)>k) low=mid+1;
        else high=mid-1;
    }
    return low;
}

int main(){
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    cout<<painterPart(boards,k)<<endl;
    cout<<painterPartOptimal(boards,k)<<endl;
    return 0;
}