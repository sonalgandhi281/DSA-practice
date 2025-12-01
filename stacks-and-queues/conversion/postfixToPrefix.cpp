#include <iostream>
using namespace std;

//if operand, put into stack
//if operator, pop tops from stack 2 times, push operator top2 top1 back into stack

//tc-> O(n)+O(n), sc-> O(n)

string postfixToPrefix(string s){
    int i=0, n=s.size();
    stack<string> st;
    while(i<n){
        if(isalnum(s[i])) st.push(string(1,s[i]));
        else{
            string top1=st.top();
            st.pop();
            string top2=st.top();
            st.pop();
            string conv=s[i]+top2+top1;
            st.push(conv);
        }
        i++;
    }
    return st.top();
}

int main(){
    cout<<postfixToPrefix("AB-DE+F*/")<<endl;
    return 0;
}