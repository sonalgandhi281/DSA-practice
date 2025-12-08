#include <iostream>
using namespace std;

//Given an integer array nums, determine the range of a subarray, defined as the difference between the largest and smallest elements within the subarray. Calculate and return the sum of all subarray ranges of nums.

//Brute: find each subarray, for each find min and max element, add their difference to sum

//tc-> O(n^2), sc-> O(1)

long long sumSubarrRanges(vector<int> &arr){
    int n=arr.size();
    long long sum=0;
    for(int i=0;i<n;i++){
        int largest=arr[i], smallest=arr[i];
        for(int j=i;j<n;j++){
            largest=max(largest,arr[j]);
            smallest=min(smallest,arr[j]);
            sum+=largest-smallest;
        }
    }
    return sum;
}

//Optimal: maybe instead of finding all subarrays, i can think about each element and calc ki ye element kitni subarrays me as minimum ya maximum element contribute karega

//i can calculate sum of subarray minimums and sum of subarray maximums, subract both of them to get the ans

//tc-> O(10n), sc-> O(10n)

vector<int> findpse(vector<int> &arr){
    int n=arr.size();
    vector<int> ans(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
        ans[i]=st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}

vector<int> findnse(vector<int> &arr){
    int n=arr.size();
    vector<int> ans(n,n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        ans[i]=st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}

vector<int> findpge(vector<int> &arr){
    int n=arr.size();
    vector<int> ans(n,-1);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]<arr[i]) st.pop();
        ans[i]=st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}

vector<int> findnge(vector<int> &arr){
    int n=arr.size();
    vector<int> ans(n,n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
        ans[i]=st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}

long long sumMax(vector<int> &arr){
    int n=arr.size();
    long long sum=0;
    vector<int> pge=findpge(arr);
    vector<int> nge=findnge(arr);
    for(int i=0;i<n;i++){
        int left=i-pge[i];
        int right=nge[i]-i;
        long long freq=(left*right*1LL);
        sum+=(freq*arr[i]*1LL);
    }
    return sum;
}

long long sumMin(vector<int> &arr){ //to calc sum of subarray minimums
    int n=arr.size();
    long long sum=0;
    vector<int> pse=findpse(arr);
    vector<int> nse=findnse(arr);
    for(int i=0;i<n;i++){
        int left=i-pse[i];
        int right=nse[i]-i;
        long long freq=(left*right*1LL);
        long long val=(freq*arr[i]*1LL);
        sum+=val;
    }
    return sum;
}

long long sumSubarrRangesOptimal(vector<int> &arr){
    return (sumMax(arr)-sumMin(arr));
}

int main(){
    vector<int> v={4,-2,-3,4,1};
    cout<<sumSubarrRanges(v)<<endl;
    cout<<sumSubarrRangesOptimal(v);
}