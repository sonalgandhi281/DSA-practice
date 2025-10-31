#include<iostream>
using namespace std;

//3. upper bound : smallest index such that arr[ind]>x

//Brute: linear search, tc->O(n)

//Optimal: same approach as lower bound problem just change condition
//tc-> O(logn)

int upperBound(vector<int>&arr, int x){
    int n=arr.size();
    int low=0, high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>x){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

//stl upper bound function in c++

int ub(vector<int>&arr, int x){
    int ub=upper_bound(arr.begin(),arr.end(),x)-arr.begin();
    return ub;
}

int main(){
    vector<int> v={3,5,8,9,15,19};
    int x=9;
    cout<<upperBound(v,x)<<endl;
    cout<<ub(v,x)<<endl;

    return 0;
}

