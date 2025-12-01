#include <iostream>
using namespace std;

//if operand, push to stack.
//if operator, pop last 2 elements of stack, put operator in between, wrap entire expression in () and push back into stack.

//tc-> O(n)+O(n), sc->O(n)

string postfixToInfix(string s){
    int i=0, n=s.size();
    stack<string> st;
    while(i<n){ //O(n)
        if(isalnum(s[i])){
            st.push(string(1,s[i]));
        }
        else{
            string t1=st.top();
            st.pop();
            string t2=st.top();
            st.pop();
            string conv="("+t2+s[i]+t1+")"; //O(n1+n2) addition of 2 strings can take time
            st.push(conv);
        }
        i++;
    }
    return st.top();
}

int main(){
    cout<<postfixToInfix("AB-DE+F*/")<<endl;
    return 0;
}