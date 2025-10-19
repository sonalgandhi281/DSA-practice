#include<iostream>
#include<unordered_map>
using namespace std;

//27. find no. of subarrays with the sum K

//Brute: generate all subarrays, find ones with sum K, count.
//TC-> O(n^3), SC-> O(1)

int subArrSumK(vector<int> &arr, int target){
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            if(sum==target) cnt++;
        }
    }
    return cnt;
}

//Better: reduce in to 2 loops only bcz we can accumulate sum while moving j only.
//TC-> O(n^2), SC-> O(1)

int subArrSumKBetter(vector<int> &arr, int target){
    int n=arr.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==target) cnt++;
        }
    }
    return cnt;
}

//Optimal: using prefixSum. we find prefix sum till each index. lets say i have prefix sum x till a particular index and i am looking for target sum k, so remaining portion will be x-k. so, if prefix sum x-k exists, then k exists and i can increase count. how many x-k exists determines how much count will increase.

//no. of x-k = no. of k

//TC-> O(nlogn) for map or O(n) for unordered avg case and O(n^2) for unordered worst case, SC-> O(n)

int subArrSumKOptimal(vector<int> &arr, int target){
    int n=arr.size();
    int preSum=0;
    int cnt=0;
    unordered_map<int,int> mpp;
    mpp[0]=1;
    for(int i=0;i<n;i++){
        preSum+=arr[i];
        int rem=preSum-target;
        cnt+=mpp[rem];
        mpp[preSum]+=1;
    }
    return cnt;
}

int main(){
    vector<int> v={1,2,3,-3,1,1,1,4,2,-3};
    int k=3;
    cout<<subArrSumK(v,k)<<endl;
    cout<<subArrSumKBetter(v,k)<<endl;
    cout<<subArrSumKOptimal(v,k)<<endl;
    return 0;
}