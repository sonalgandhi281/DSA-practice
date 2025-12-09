#include <iostream>
using namespace std;

// Given an array of integers arr, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

//Brute: for each value of i that ranges from 0 to n-k, move j k times and keep updating max value in that interval, store in ans

//tc-> O((n-k)*k), sc-> O(n-k+1) to return ans

vector<int> slidingWindowMax(vector<int> &arr, int k){
    int n=arr.size();
    vector<int> ans(n-k+1);
    for(int i=0;i<=n-k;i++){
        int maxnum=arr[i];
        for(int j=i;j<k+i;j++){
            maxnum=max(maxnum,arr[j]);
        }
        ans[i]=maxnum;
    }
    return ans;
}

//Optimal: traverse while keeping track of k elements. if u exceed k while traversing, trim off element from start. so i need a data structure that adds and deletes. we use double ended queue.

//now, to get maximum, if i scan each element it will take lot of time. so, i will use monotonic stack and store elements in decreasing order.

//(whenever u need greatest or smallest in constant tc think of monotonic stack)

//tc-> O(2n), n for traversal n for popping etc
//sc-> O(k)+O(n-k), for dq and list


vector<int> slidingWindowMaxOptimal(vector<int> &arr, int k){
    vector<int> ans;
    deque<int> dq;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(!dq.empty() && dq.front()<=i-k) dq.pop_front();
        while(!dq.empty() && arr[dq.back()]<arr[i]) dq.pop_back();
        dq.push_back(i);
        if(i>=k-1){
            ans.push_back(arr[dq.front()]);
        }
    }
    return ans;
}


int main(){
    vector<int> v={1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<int> ans1=slidingWindowMax(v,k);
    for(int x:ans1) cout<<x<<" ";
    cout<<endl;
    vector<int> ans2=slidingWindowMaxOptimal(v,k);
    for(int x:ans2) cout<<x<<" ";
}