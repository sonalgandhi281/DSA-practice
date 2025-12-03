#include <iostream>
using namespace std;

//Brute: for each element loop from next to last and stop when u find smaller element
//tc-> O(n^2), sc-> O(n)

//Optimal:
//just like next greater element but store elements in increasing order in monotonic stack and change condition

//tc-> O(2n), sc-> O(n)

vector <int> nse(vector<int> &arr){
    int n=arr.size();
    stack<int> st;
    vector<int> ans(n,-1);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()>=arr[i]) st.pop();
        ans[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return ans;
}

int main(){
    vector<int> v={4,8,5,2,25};
    vector<int> ans=nse(v);
    for(int x:ans) cout<<x<<" ";
    return 0;
}