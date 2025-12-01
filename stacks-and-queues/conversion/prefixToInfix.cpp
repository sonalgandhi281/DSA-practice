#include <iostream>
using namespace std;

//iterate from back
//if operand, put in stack
//if operator, take out tops and put back (top1 operator top2) into the stack

//tc-> O(n)+O(n), sc-> O(n)

string prefixToInfix(string s){
    int n=s.size();
    int i=n-1;
    stack<string> st;
    while(i>=0){
        if(isalnum(s[i])) st.push(string(1,s[i]));
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string conv="("+t1+s[i]+t2+")";
            st.push(conv);
        }
        i--;
    }
    return st.top();
}

int main(){
    cout<<prefixToInfix("*+PQ-MN");
    return 0;
}