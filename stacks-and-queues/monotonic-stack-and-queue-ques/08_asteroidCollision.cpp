#include <iostream>
using namespace std;

//collision only happens if theres +ve followed by -ve

//positive element ho to push into stack, otherwise, negative element hai to keep comparing with stack top and pop if lesser value. if stack becomes empty or top is -ve, push element into stack

//tc-> O(2n), sc-> O(n)

vector<int> asteroid(vector<int> &arr){
    int n=arr.size();
    vector<int> st; //i can also use stack but then reverse it by popping out all elements and pushing in a list, before returning ans
    for(int i=0;i<n;i++){
        if(arr[i]>0) st.push_back(arr[i]);
        else{
            while(!st.empty() && st.back()>0 && st.back()<abs(arr[i])) st.pop_back();
            if(!st.empty() && st.back()==abs(arr[i])) st.pop_back();
            else if(st.empty() || st.back()<0) st.push_back(arr[i]);
        }
    }
    return st;
}

int main(){
    vector<int> v={3,5,-6,2,-1,4};
    vector<int> ans=asteroid(v);
    for(int x:ans) cout<<x<<" ";
}