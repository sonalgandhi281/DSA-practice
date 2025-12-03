#include <iostream>
using namespace std;

//monotonic stack: when we use stack to store elements in a particular order

//for every element in the array, find out next greater element

//Brute
//tc-> O(n^2), sc-> O(n) to return the ans
vector<int> nge(vector<int> &arr){
    int n=arr.size();
    vector<int> v(n,-1);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                v[i]=arr[j];
                break;
            }
        }
    }
    return v;
}

//Optimal: traverse from back and keep storing elements in decreasing order in stack

//tc-> O(2n) at worst case, bcz while loop is not running for n everytime. 
//sc-> O(2n) for stack and to return the ans

vector<int> ngeOptimal(vector<int> &arr){
    int n=arr.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        if(st.empty()) ans[i]=-1;
        else ans[i]=st.top();
        st.push(arr[i]);
    }
    return ans;
}

int main(){
    vector<int> v={1,3,4,2};
    vector<int> ans1=nge(v);
    vector<int> ans2=ngeOptimal(v);
    for(int x:ans1) cout<<x<<" ";
    cout<<endl;
    for(int x:ans2) cout<<x<<" ";
}