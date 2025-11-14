#include <iostream>
using namespace std;

//5. given an array and a threshold value, find smallest divisor that on dividing every element, taking ceil value and adding it up, we get <= threshold.

// range of divisors will be from 1 to max element of array

//Brute:
//O(n*max(arr))

int smallestDivisor(vector<int> &arr, int threshold){
    int maxi=*max_element(arr.begin(),arr.end());
    int n=arr.size();
    for(int i=1;i<=maxi;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=ceil((double)arr[j]/(double)i);
        }
        if(sum<=threshold){
            return i;
        }
    }
    return -1;
}

//Optimal: 
//O(n * log(max(arr)))

int div(vector<int>&arr, int mid){
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=ceil((double)arr[i]/(double)mid);
    }
    return sum;
}

int smallestDivisorOptimal(vector<int> &arr, int threshold){
    int n=arr.size();
    if(n>threshold) return -1;
    int maxi=*max_element(arr.begin(),arr.end());
    int low=1, high=maxi;
    while(low<=high){
        int mid=(low+high)/2;
        int val=div(arr,mid);
        if(val<=threshold) high=mid-1;
        else low=mid+1;
    }
    return low;
}

int main(){
    vector<int> v={1,2,3,4,5};
    int threshold=8;
    cout<<smallestDivisor(v,threshold)<<endl;
    cout<<smallestDivisorOptimal(v,threshold)<<endl;
    return 0;
}