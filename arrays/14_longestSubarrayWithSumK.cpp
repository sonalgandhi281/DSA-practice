#include <iostream>
#include <map>
using namespace std;

//subarray: contiguous part of the array

//14. return length of longest subarray with sum k

//Brute: find all subarrays, then all that give sum k, then find longest
//TC-> O(n^3), SC-> O(1)

int longestSubarray(vector<int> &arr, int k){
    int n=arr.size();
    int len=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            long long sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            if(sum==k){
                len=max(len,j-i+1);
            }
        }
    }
    return len;
}

//Brute Modified: can be reduced to 2 nested loops based on the fact that j loop keeps track of both end and the current element, and sum of subarray is sum of prev subarray+current element
//TC-> O(n^2), SC-> O(1)

int longestSubarrayB(vector<int> &arr, int k){
    int n=arr.size();
    int len=0;
    for(int i=0;i<n;i++){
        long long sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==k){
                len=max(len,j-i+1);
            }
        }
    }
    return len;
}

//Better: Hashing. PrefixSum approach. 
// puri array ke liye, har index pe uska prefixsum calculate kar lenge. and then jab hume subarray ka sum nikalna hoga so we dont need another loop, we can just calculate by accessing prefixsum values
//subarraySum(i,j) = ps[j]-ps[i-1]

// Traverse array, find prefix sum at each index and store in map. if prefixSum == k, then len=max(len,i+1). calculate prefixSum-k and check if its already in map. if it is, then k also exists. find length and update len accordingly.

//works for both +ves and -ves. 

//TC-> O(nlogn) for map, for unordered map-> O(n) avg case, O(n^2) worst case
//SC-> O(n)

int longestSubarrayBetter(vector<int> &arr, long long k){
    map<long long, int> preSumMap; //<prefixSum, index>
    int n=arr.size();
    long long sum=0;
    int maxlen=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==k){
            maxlen=max(maxlen,i+1);
        }
        long long rem = sum-k;
        if(preSumMap.find(rem)!=preSumMap.end()){
            int len = i-preSumMap[rem];
            maxlen=max(maxlen,len);
        }
        if(preSumMap.find(sum)==preSumMap.end()){ //edge case if array contains zeros as well, then we need to check left most
            preSumMap[sum]=i;
        }
    }
    return maxlen;
}

//Optimised: 2 pointer and greedy
//works for +ve element arrays only
// when we move right in the array, sum will increase. if it goes beyond our target sum, we trim down the array

//TC-> O(2n), SC-> O(1)

int longestSubarrayOptimal(vector<int> &arr, long long k){
    int n=arr.size();
    int left=0,right=0, maxlen=0;
    long long sum=arr[0];
    while(right<n){
        while(left<=right && sum>k){
            sum-=arr[left];
            left++;
        }
        if(sum==k){
            maxlen=max(maxlen, right-left+1);
        }
        right++;
        if(right<n) sum+=arr[right];
    }
    return maxlen;
}

int main(){
    vector<int> v={1,1,1,2,2,4,3};
    int target=3;
    cout<<longestSubarray(v,target)<<endl;
    cout<<longestSubarrayB(v,target)<<endl;
    cout<<longestSubarrayBetter(v,target)<<endl;
    cout<<longestSubarrayOptimal(v,target)<<endl;
    return 0;
}