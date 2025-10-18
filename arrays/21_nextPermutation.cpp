#include<iostream>
using namespace std;

//21. next permutation

//permutaions: n elements have n! ways to be arranged. we have to find next permutation in sorted order

//Brute: generate all permutations (by recursion (lec12,13)) in sorted order. then do linear search to find given permutation. then, return next permutation.
//TC-> O(nxn!), SC-> O(1)

//Better: using built in next_permutation() function in stl c++

vector<int> nextPerm(vector<int>&arr){
    next_permutation(arr.begin(),arr.end());
    return arr;
}

//can i implement this inbuilt stl function? yes.

//Optimal: 

//Intuition: next permutation will have longer prefix match with current permutation.


//find longest prefix match by finding a break point by traversing from n-2 to 0 until we get a[i]<a[i+1]
//then traverse from n-1 to i+1 to find smallest element greater than a[i]
//now i want to place remaining elements in sorted order

vector<int> nextPermOptimal(vector<int>&arr){
    int n=arr.size();
    int index=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            index=i;
            break;
        }
    }
    if(index==-1){
        reverse(arr.begin(),arr.end());
        return arr;
    }
    for(int i=n-1;i>=index+1;i--){
        if(arr[i]>arr[index]){
            swap(arr[i],arr[index]);
            break;
        }
    }
    reverse(arr.begin()+index+1,arr.end());
    return arr;
}

int main(){
    vector<int> v1={2,1,5,4,3,0,0};
    vector<int> v2={2,1,5,4,3,0,0};
    vector<int>ans1 = nextPerm(v1);
    vector<int>ans2 = nextPermOptimal(v2);

    for(int x:ans1) cout<<x<<" ";
    cout<<endl;
    for(int x:ans2) cout<<x<<" ";

    return 0;
}