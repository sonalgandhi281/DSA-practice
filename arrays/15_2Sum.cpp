#include <iostream>
#include <map>
using namespace std;

//Two sum problem (2 varieties)

//Variety 1: given an array and a target no., return true if a and b exist such that a+b = target, return false otherwise.

//Variety 2: we are sure that a and b exist in array such that a+b=target. return their indices.

//Brute: pick up each element and check with every other element if it sums up the target
//TC-> O(n^2), SC-> O(1)

//improvised brute: if {2,4,5} is array and we've already checked for 2,4 , then we dont have to check for 4,2 again. so, for every element start checking from next element 
//so, instead of j looping from 0 to n, we loop from i+1 to n
//tc still equivalent to O(n^2) but slightly better.

bool twoSum1(vector<int> &arr, int target){
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            //if(i==j) continue;
            if(arr[i]+arr[j]==target) return true;
        }
    }
    return false;
}


vector<int> twoSum2(vector<int> &arr, int target){
    int n=arr.size();
    vector<int> indices;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j]==target){
                indices.push_back(i);
                indices.push_back(j);
                return indices;
            }
        }
    }
    return indices; //wont run if correct input given
}

//Better: Hashing. use hashmap to check if target-selected_element exists.
//TC-> O(nlogn) map, O(n) unordered map avg or O(n^2) unordered worst case
//SC-> O(n)

vector<int> twoSumBetter(vector<int> &arr, int target){
    int n=arr.size();
    vector<int> ans;
    map<int,int> mpp; //<element, index>
    for(int i=0;i<n;i++){
        int rem=target-arr[i];
        if(mpp.find(rem)!=mpp.end()){
            ans.push_back(i);
            ans.push_back(mpp[rem]);
            return ans; //or return true incase of variety1
        }
        mpp[arr[i]]=i;
    }
    return ans;  //wont run if correct input given
}

//Optimal: implement this without map ds.
//2 pointer: greedy approach.
//sort the array, keep left and right pointer. if sum<target, left++.
//if sum>target, right--. if sum==target return true

//optimally sorts only the 1st variety. 
//tc->O(nlogn for sorting +n), sc->O(n for sorting) otherwise O(1) if u dont consider sorting

bool twoSumOptimal1(vector<int> &arr, int target){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int left=0, right=n-1;
    while(left<right){
        int sum=arr[left]+arr[right];
        if(sum==target) return true;
        else if(sum<target) left++;
        else right--;
    }
    return false;
}

//for 2nd variant, we will have to use another ds to store both element and its index in original array, so that i can still return original index after sorting. 
//tc-> O(n+nlogn), sc->O(1) 
//not optimal for variety 2

vector<int> twoSumOptimal2(vector<int> &arr, int target){
    int n=arr.size();
    vector<pair<int,int>> v; //pair of (value, original index)
    for(int i=0;i<n;i++){
        v.push_back({arr[i],i});
    }
    sort(v.begin(),v.end()); //sort by value
    int left=0, right=n-1;
    while(left<right){
        int sum=v[left].first+v[right].first;
        if(sum==target) return {v[left].second,v[right].second};
        else if(sum<target) left++;
        else right--;
    }
    return {}; //no pair found
}

int main(){
    vector<int> a={3,4,6,8,2,1};
    int target=14;
    cout<<twoSum1(a,target)<<endl;
    cout<<twoSumOptimal1(a,target)<<endl;

    vector<int>ans1=twoSum2(a,target);
    vector<int>ans2=twoSumBetter(a,target);
    vector<int>ans3=twoSumOptimal2(a,target);

    for(int x:ans1) cout<<x<<" ";
    cout<<endl;
    for(int x:ans2) cout<<x<<" ";
    cout<<endl;
    for(int x:ans3) cout<<x<<" ";
    cout<<endl;

    return 0;
}