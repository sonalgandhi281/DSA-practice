#include <iostream>
using namespace std;

// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

//intuition: we're trying to place smaller digits in start and remove large values

//traverse the string, put element in stack if the stack top is greater than num[i] and pop. we can pop k times.

//when k is exhausted, put all elements into stack.

//edge cases: k==n (then ans will be "0"), if u end up with number like 00100 (with leading 0s), so trim of initial 0s.
//if u have num="123456", k=3, stack will have all elements. so, if k is not exhausted, remove last k elements (pop k times)

//tc-> O(3n+k), sc-> O(n)

string remove(string s, int k){
    stack<char> st;
    int n=s.size();
    for(int i=0;i<n;i++){
        while(!st.empty() && k>0 && (st.top()-'0')>(s[i]-'0')){
            st.pop();
            k--;
        }
        st.push(s[i]);
    }
    while(k>0){
        st.pop();
        k--;
    }
    if(st.empty()) return "0";
    string ans="";
    while(!st.empty()){
        ans=ans+st.top();
        st.pop();
    }
    while(ans.size()!=0 && ans.back()=='0') ans.pop_back();
    reverse(ans.begin(),ans.end());
    if(ans.empty()) return "0";
    return ans;
}

int main(){
    cout<<remove("1432219",3);
}