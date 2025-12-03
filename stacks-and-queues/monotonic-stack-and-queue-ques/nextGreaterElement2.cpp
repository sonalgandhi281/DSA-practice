#include <iostream>
using namespace std;

//find next greater element in circular array

//Extreme Brute: for each element i, first look for next greater from i+1 to n-1, then look in 0 to i-1.

//Brute: if i double the array hypothetically, eg [2,10,12,1,11] will be[2,10,12,1,11,2,10,12,1,11]
//i can map indexes to i%n

//tc-> O(n^2), sc-> O(n)

vector<int> nge2(vector<int> &arr){
    int n=arr.size();
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<i+n;j++){
            int ind=j%n;
            if(arr[ind]>arr[i]){
                ans[i]=arr[ind];
                break;
            }
        }
    }
    return ans;
}

//Optimal: using monotonic stack
//hypothetically double the array
//or we can say that do stack approach twice

//tc-> O(4n), sc-> O(2n)

vector<int> nge2Optimal(vector<int> &arr){
    int n=arr.size();
    stack<int> st;
    vector<int> ans(n,-1);
    for(int i=2*n-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i%n]){
            st.pop();
        }
        if(i<n){ //only then i looking for nge
            ans[i] = st.empty() ? -1 : st.top();
        }
        st.push(arr[i%n]);
    }
    return ans;
}

int main(){
    vector<int> v={1,2,3,4,3};
    vector<int> ans1=nge2(v);
    vector<int> ans2=nge2Optimal(v);
    for(int x:ans1) cout<<x<<" ";
    cout<<endl;
    for(int x:ans2) cout<<x<<" ";
}