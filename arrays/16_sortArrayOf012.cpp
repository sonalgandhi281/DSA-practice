#include <iostream>
using namespace std;

//16. sort an arrat of 0s, 1s and 2s

//Brute: using sorting algos like merge sort
//TC-> O(nlogn), SC-> O(n)

//Better: keeping count of values of 0s, 1s, 2s. traverse array, maintain values in 3 count vars, rewrite array.
//TC-> O(2n), SC-> O(1)

void sortArr012(vector<int> &arr){
    int n=arr.size();
    int c0=0,c1=0,c2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) c0++;
        else if(arr[i]==1) c1++;
        else c2++;
    }
    for(int i=0;i<c0;i++){
        arr[i]=0;
    }
    for(int i=c0;i<c0+c1;i++){
        arr[i]=1;
    }
    for(int i=c0+c1;i<n;i++){
        arr[i]=2;
    }
}

//Optimal: Dutch National Flag Algorithm

//3 pointers: low, mid, high.
//3 rules:
//a[0 to low-1] will be 0 (extreme left)
//a[low to mid-1] will be 1
//a[high+1,n-1] will be 2 (extreme right)

// a[mid,high] is unsorted

//TC-> O(n), SC-> O(1)

void sortArr012Optimal(vector<int> &arr){
    int n=arr.size();
    int low=0, mid=0, high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid]==1) mid++;
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main(){
    vector<int> v1={1,0,2,2,1,1,0,2};
    vector<int> v2={1,0,2,2,1,1,0,2};
    sortArr012(v1);
    sortArr012Optimal(v2);
    for(int x: v1) cout<<x<<" ";
    cout<<endl;
    for(int x: v2) cout<<x<<" ";
    return 0;
}