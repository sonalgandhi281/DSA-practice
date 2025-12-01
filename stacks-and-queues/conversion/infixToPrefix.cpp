#include <iostream>
using namespace std;

//reverse given infix, after reversing scan through it and convert ( to ) and vice versa

//controlled conversion:

//do infix to postfix conversion. but, only pop operator from stack if priority of s[i] is strictly less than top of stack (cant even be equal priority like in infix to postfix conversion)

//also, two ^ cant be together bcz we take out anything with priority similar or greater.

//reverse the ans


//tc-> O(n/2)+O(n/2)+O(2n) = O(3n)
//sc-> O(n)

int priority(char c){
    if(c=='^') return 3;
    else if(c=='*' || c=='/') return 2;
    else if(c=='+' || c=='-') return 1;
    return -1;
}

string infixToPrefix(string s){
    int i=0, n=s.size();
    stack<char> st;
    string ans="";
    reverse(s.begin(),s.end()); //O(n) or O(n/2)
    for(int i=0;i<n;i++){
        if(s[i]=='(') s[i]=')';
        else if(s[i]==')') s[i]='(';
    }
    while(i<n){
        if((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')){
            ans+=s[i];
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
            if(s[i]=='^'){
                while(!st.empty() && priority(s[i])<=priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            }
            else{
                while(!st.empty() && priority(s[i])<priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    cout<<infixToPrefix("(A+B)*C-D+F")<<endl;
    return 0;
}