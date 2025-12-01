#include <iostream>
using namespace std;

//if symbol scanned is operand, add it to ans, if operator, check if its priority is less than or equal to operator in stack. if yes, pop elements from stack till priority is <= stack element, then push operator. otherwise, push operator in stack.

//tc-> O(n)+O(n), sc-> O(n)+O(n)

int priority(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    return -1;
}

string infixToPostfix(string s){
    int i=0, n=s.size();
    stack<char> st;
    string ans="";
    while(i<n){
        if((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')){
            ans=ans+s[i];
        }
        else if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && priority(s[i])<=priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans=ans+st.top();
        st.pop();
    }
    return ans;
}

int main(){
    cout<<infixToPostfix("a+b*(c^d-e)")<<endl;
    return 0;
}