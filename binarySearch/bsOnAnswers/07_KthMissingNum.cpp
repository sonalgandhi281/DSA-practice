#include <iostream>
using namespace std;

//7. given an array and a number k, find the Kth positive missing number.

//eg
//[4,7,9,10], k=1, ans=1; k=4, ans=5

//Brute: note that ans shifts or increases when array has an element less than or equal to k, so we update k accordingly and stop when we find greater element

//tc->O(n), sc->O(1)

int kthMissing(vector<int> &arr, int k){
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]<=k) k++;
        else break;
    }
    return k;
}

//Optimal: 
//note we cannot apply normal binary search bcz missing element (the one we are searching) is not in the array. also, we cant apply bs on answers (bcz we're not maximizing or minimizing anything), (we dont notice pattern of possible and not possible range)

//if i can figure out between which indexes my ans should have been, i can solve this

//tc-> O(logn), sc-> O(1)

int kthMissingOptimal(vector<int> &arr, int k){
    int n=arr.size();
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        int missing=arr[mid]-(mid+1);
        if(missing<k) low=mid+1;
        else high=mid-1;
    }
    return k+high+1;
}

int main(){
    vector<int> v={4,7,9,10};
    int k=4;
    cout<<kthMissing(v,k)<<endl;
    cout<<kthMissingOptimal(v,k)<<endl;
    return 0;
}