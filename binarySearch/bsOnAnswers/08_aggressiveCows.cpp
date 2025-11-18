#include <iostream>
using namespace std;

//this is 2nd type of pattern of binary search on ans, it involves finding max of min value or vice versa

//8. Aggressive Cows

//given an array of size n which denotes the position of stalls, & given an integer k which denotes the number of aggressive cows
// assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.
// Find the maximum possible minimum distance.

//Brute: we linearly check for possible min distance from 1 to arr[n-1]-arr[0]. as soon as we get max distance possible, we return it.
//tc-> O(n * (maxDist-arr[0])) + O(nlogn)

bool canWePlace(vector<int> &arr, int dist, int cows){
    int n=arr.size();
    int cntCows=1, last=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-last >= dist){
            cntCows++;
            last=arr[i];
        }
        if(cntCows>=cows) return true;
    }
    return false;
}

int aggCows(vector<int> &arr, int cows){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int maxDist=arr[n-1]-arr[0];
    for(int i=1;i<=maxDist;i++){
        if(canWePlace(arr,i,cows)) continue;
        else return (i-1);
    }
    return maxDist;
}

//Optimal: binary search on ans
//tc-> O(n * log(maxDist-arr[0]))+O(nlogn)

int aggCowsOptimal(vector<int> &arr, int cows){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int low=1, high=arr[n-1]-arr[0]; //here, we can also keep low as min dist bw 2 consecutive stalls (to optimize the range a bit)
    while(low<=high){
        int mid=(low+high)/2;
        if(canWePlace(arr,mid,cows)==true) low=mid+1;
        else high=mid-1;
    }
    return high;
}

int main(){
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    cout<<aggCows(stalls,k)<<endl;
    cout<<aggCowsOptimal(stalls,k)<<endl;
    return 0;
}