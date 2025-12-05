#include <iostream>
using namespace std;

//Nearest Smaller Element: given an array of integers, for every element find the nearest smaller element on the left (previous smaller element)

//Brute: for every element at i, iterate backwards fro. i-1 to 0 till u find smaller element
//tc-> O(n^2), sc-> O(n)

vector<int> pse(vector<int> &arr){
    int n=arr.size();
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]){
                ans[i]=arr[j];
                break;
            }
        }
    }
    return ans;
}

//Optimal: im searching in left, so iteration should start from left. 
//tc-> O(2n), sc-> O(2n)

vector<int> pseOptimal(vector<int> &arr){
    int n=arr.size();
    stack<int> st;
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>=arr[i]){
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return ans;
}

int main(){
    vector<int> v={9,2,4,5,1,6};
    vector<int> ans1=pse(v);
    vector<int> ans2=pseOptimal(v);
    for(int x:ans1) cout<<x<<" ";
    cout<<endl;
    for(int x:ans2) cout<<x<<" ";
}