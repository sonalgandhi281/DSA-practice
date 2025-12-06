#include <iostream>
using namespace std;

// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.


//Brute: find all subarrays by taking a starting index and extending ending index and while extending find minimum of that subarray and add in sum
//tc-> O(n^2), sc-> O(1)

int sumSubarrayMins(vector<int>& arr) {
       int n=arr.size();
       long long sum=0;
       long long mod=1e9+7;
       for(int i=0;i<n;i++){
        long long mini=arr[i];
        for(int j=i;j<n;j++){
            mini=min(mini,(long long)arr[j]);
            sum=(sum+mini)%mod;
        }
       }
       return (int)sum;
    }

//Optimal: instead of finding all subarrays, focus on each element's contribution. (how many times each element acts as minimum)
//for each element, we find nse and pse index to find no. of subarrays possible. then multiply element with this frequency and add to sum.

//tc-> O(n) bcz nse and pse take O(2n) each and calc sum also takes O(n), sc-> O(n) overall bcz of stack and vectors.

vector <int> findnse(vector<int> &arr){
    int n=arr.size();
    stack<int> st;
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}

vector<int> findpse(vector<int> &arr){
    int n=arr.size();
    stack<int> st;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}

int sumSubarrMinOptimal(vector<int> &arr){
    int n=arr.size();
    vector<int> nse=findnse(arr);
    vector<int> pse=findpse(arr);
    int mod=1e9+7;
    int sum=0;
    for(int i=0;i<n;i++){
        int left=i-pse[i];
        int right=nse[i]-i;
        long long subarr=left*right*1LL;
        int val=(subarr*arr[i]*1LL)%mod;
        sum=(sum+val)%mod;
    }
    return sum;
}

int main(){
    vector<int> arr = {3, 1, 2, 5};
    cout<<sumSubarrayMins(arr)<<endl;
    cout<<sumSubarrMinOptimal(arr)<<endl;
}