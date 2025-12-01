#include <iostream>
using namespace std;

//iterate from back
//if operand, add to stack
//if operator, pop out 2 times from stack and push top1 top2 operator

//tc-> O(2n), sc-> O(n)

string prefixToPostfix(string s){
    int n=s.size();
    int i=n-1;
    stack<string> st;
    while(i>=0){
        if(isalnum(s[i])) st.push(string(1,s[i]));
        else{
            string top1=st.top();
            st.pop();
            string top2=st.top();
            st.pop();
            string conv=top1+top2+s[i];
            st.push(conv);
        }
        i--;
    }
    return st.top();
}

int main(){
    cout<<prefixToPostfix("/-AB*+DEF")<<endl;
    return 0;
}