#include <iostream>
using namespace std;

//10. split array - largest sum
// Given an integer array ‘A’ of size ‘N’ and an integer ‘K'. Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized. Your task is to return the minimized largest sum of the split.

//Brute:
//O(n * (sum-max+1))
int countPart(vector<int> &arr, int maxSum){
    int splitCnt=1, sum=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(sum+arr[i] <= maxSum){
            sum+=arr[i];
        }else{
            splitCnt++;
            sum=arr[i];
        }
    }
    return splitCnt;
}

int splitArr(vector<int> &arr, int k){
    int maxi=*max_element(arr.begin(),arr.end());
    int sum=0;
    for(int x:arr) sum+=x;
    for(int i=maxi;i<sum;i++){
        if(countPart(arr,i)==k) return i;
    }
    return sum;
}

//Optimal:
//O(n * log(sum-max+1))

int splitArrOptimal(vector<int> &arr, int k){
    int low=*max_element(arr.begin(),arr.end());
    int high=0;
    for(int x:arr) high+=x;
    while(low<=high){
        int mid=(low+high)/2;
        if(countPart(arr,mid)>k) low=mid+1;
        else high=mid-1;
    }
    return low;
}

int main(){
    vector<int> v={1,2,3,4,5};
    int k=3;
    cout<<splitArr(v,k)<<endl;
    cout<<splitArrOptimal(v,k)<<endl;
    return 0;
}