#include<iostream>
using namespace std;

//5. floor and ceil in sorted array

// floor: largest no. in array <= x
// ceil: smallest no. in array >= x (lower bound)
// ans=-1 if it doesnt exist

//eg
//[10,20,30,40,50], x=25
//floor=20, ceil=30

//tc-> O(logn), sc-> O(1)

int floorVal(vector<int> &arr, int x){
    int n=arr.size();
    int low=0, high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]<=x){
            ans=arr[mid];
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}

int ceilVal(vector<int> &arr, int x){
    int n=arr.size();
    int low=0, high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=x){
            ans=arr[mid];
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}
//note: we dont need ans variable to return the ans
//either of the pointers low and high will always hold ans

//floor: high
//ceil: low

pair<int, int> floorAndCeil(vector<int> &arr, int x){
    int f=floorVal(arr,x);
    int c=ceilVal(arr,x);
    return make_pair(f,c);
}

int main(){
    vector<int> v={3,4,4,7,8,10};
    int x=5;
    pair<int, int> ans=floorAndCeil(v,x);
    cout<<ans.first<<" "<<ans.second<<endl;
    return 0;
}