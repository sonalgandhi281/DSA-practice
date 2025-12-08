#include <iostream>
using namespace std;

//Brute: take subarrays, find min (it will be height), mult with width to find area
//tc-> O(n^2), sc-> O(1)
int largestRectBrute(vector<int>&arr){
    int maxArea=0, n=arr.size();
    for(int i=0;i<n;i++){
        int mini=INT_MAX;
        for(int j=i;j<n;j++){
            mini=min(mini,arr[j]);
            int width=j-i+1;
            int area=width*mini;
            maxArea=max(maxArea,area);
        }
    }
    return maxArea;
}

//Optimal 1: 

//ek way ho sakta hai ki har element ke liye me nse aur pse nikalu, fir jese ye array hai [2,1,5,6,2,3]
//nse=[1,6,4,4,6,6], pse=[-1,-1,1,2,1,4]
//from this we can find total blocks which have a particular element as min and we can multiply to find sum
//aise sabke nikalo fir max jo bhi hai vo ans

//tc-> O(5n), sc-> O(4n)

vector<int> findnse(vector<int> &arr){
    int n=arr.size();
    stack<int> st;
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
        ans[i]=st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}
vector<int> findpse(vector<int> &arr){
    int n=arr.size();
    stack<int> st;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
        ans[i]=st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}

int largestRect(vector<int> &arr){
    int n=arr.size();
    vector<int> nse=findnse(arr);
    vector<int> pse=findpse(arr);
    int maxArea=0;
    for(int i=0;i<n;i++){
        // int left=i-pse[i];
        // int right=nse[i]-i;
        int blocks=nse[i]-pse[i]-1; //blocks=left+right-1
        int sum=blocks*arr[i];
        maxArea=max(maxArea,sum);
    }
    return maxArea;
}

//Optimal 2: dont precompute and prestore nse and pse, implement soln in a single pass

//pse can be computed simultaneously while traversing array to go through each and every element
//we know that stack me se pop tab karte hai jab top se koi smaller element aa jaye. so, this element is automatically the nse.
//when u get nse and pse, apply formula arr[i]*(pse[i]+nse[i]-1)
//if u end up traversing entire array and there are elements left in stack, that means there is no nse for them (so, take n as nse)

//tc-> O(2n), n for traversal of array and n for popping/traversing stack overall
//sc-> O(n) for stack

int largestRectOptimal(vector<int> &arr){
    int n=arr.size();
    stack<int> st;
    int maxArea=0;
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            int element=st.top();
            st.pop();
            int nse=i;
            int pse=st.empty() ? -1 : st.top();
            maxArea=max(maxArea,arr[element]*(nse-pse-1));
        }
        st.push(i);
    }
    while(!st.empty()){
            int nse=n;
            int element=st.top();
            st.pop();
            int pse=st.empty() ? -1 : st.top();
            maxArea=max(maxArea,arr[element]*(nse-pse-1));
        }
    return maxArea;
}

int main(){
    vector<int> v={2,1,5,6,2,3};
    cout<<largestRectBrute(v)<<endl;
    cout<<largestRect(v)<<endl;
    cout<<largestRectOptimal(v)<<endl;
}