#include <iostream>
using namespace std;

// 18. maximum subarray sum

// Brute: consider all subarrays and then find max sum
// TC-> O(n^3), SC-> O(1)

int maxSubarrSum(vector<int> &arr)
{
    int n = arr.size(), maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

// Better: sum of subarray is sum of prev subarray + current element. so, use j to denote end and also current element.
// TC-> O(n^2), SC-> O(1)

int maxSubarrSumBetter(vector<int> &arr)
{
    int n = arr.size(), maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxSum = max(maxSum, sum);
        }
    }
    return maxSum;
}

// Optimal: Kadane's Algorithm
// if at any point my sum<0, it makes no sense to carry -ve sum forward bcz it will only reduce the summation. so, i wont take it and reset sum to 0.
// if sum>0, yes u can carry ahead

// TC-> O(n), SC-> O(1)

int maxSubarrSumOptimal(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0, maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxSum = max(maxSum, sum);
        if (sum < 0)
            sum = 0;
    }
    if (maxSum <= 0)
        maxSum = 0; // case if maxSum<=0 and ques says u can consider sum of empty subarray ie 0.
    return maxSum;
}

// follow up question: can you also return any of the subarrays with the max sum?
// we need to store start and end index. start index is the one when sum=0 and end index is the one when sum>maxi.
// tc-> O(n), sc-> O(1)

void maxSubarrSumArray(vector<int> &arr){
    int n=arr.size();
    int sum=0, maxSum=INT_MIN;
    int start=0, ansStart, ansEnd;
    for(int i=0;i<n;i++){
        if(sum==0){
            start=i;
        }
        sum+=arr[i];
        if(sum>maxSum){
            maxSum=sum;
            ansStart=start;
            ansEnd=i;
        }
        if(sum<0) sum=0;
    }
    for(int x=ansStart;x<=ansEnd;x++){
        cout<<arr[x]<<" ";
    }
}

int main(){
    vector<int> v={-2,-3,4,-1,-2,1,5,-3};
    cout<<maxSubarrSum(v)<<endl;
    cout<<maxSubarrSumBetter(v)<<endl;
    cout<<maxSubarrSumOptimal(v)<<endl;
    maxSubarrSumArray(v);
    return 0;
}