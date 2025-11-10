#include<iostream>
using namespace std;

//12. find peak element. element is considered peak if arr[i]>arr[i-1] and arr[i]>arr[i+1]. return index of peak element. if more than one peak exist, return any peak.

//brute: linearly traverse and check condition for each element.
//O(n)

int peak(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        if((i==0 || arr[i]>arr[i-1]) && (i==n-1 || arr[i]>arr[i+1])) return i;
    }
    return -1;
}

//optimal: using binary search. before peak element, there is increasing sequence and after peak element, there is decreasing sequence. we use it to figure out on which half we are and eliminate that half accordingly to reach peak.
//if we are at common lowest point, we can eliminate either half.

//tc-> O(logn)

int peakOptimal(vector<int> &arr){
    int n=arr.size();
    if(n==1) return 0;
    if(arr[0]>arr[1]) return 0;
    if(arr[n-1]>arr[n-2]) return n-1;
    int low=1, high=n-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
        else if(arr[mid]>arr[mid-1]) low=mid+1;
        else if(arr[mid]>arr[mid+1]) high=mid-1;
        else high=mid-1; //or low=mid+1 both work
    }
    return -1; //dummy return statement
}

int main(){
    vector<int> v={1,2,3,4,5,4,2};
    cout<<peak(v)<<endl;
    cout<<peakOptimal(v);
    return 0;
}