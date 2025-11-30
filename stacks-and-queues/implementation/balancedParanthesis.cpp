#include <iostream>
using namespace std;

//string is valid if:
//opening and closing bracket must be of same type
//open bracket must be closed in correct order
//every closing has corresponding opening of same type

//tc-> O(n)
//sc-> O(n)

bool balanced(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{') st.push(s[i]);
        else{
            if(st.empty()) return false; //means that closing bracket doesnt have corresponding opening
            char ch=st.top();
            st.pop();
            if((s[i]=='(' && ch==')') || (s[i]=='[' && ch==']') || (s[i]=='{' && ch=='}')){
                continue;
            }
            else return false;
        }
    }
    return st.empty();
}

int main(){
    cout<<balanced("([]{}{[]})");
    return 0;
}