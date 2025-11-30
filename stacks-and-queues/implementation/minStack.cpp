#include <iostream>
using namespace std;

//built a stack that also implements getMin function

//Brute: scan through the stack to find minimum, but that will take O(n) tc. 

//Better:
//modify stack to store pair of elements. pair<int,int> will store val, min seen till now

//tc->O(1), sc-> O(2n)

class ST{
    public:
    stack<pair<int,int>> st;
    void push(int val){
        if(st.empty()){
            st.push({val,val});
        }else{
            st.push({val,min(val,st.top().second)});
        }
    }
    int getMin(){
        return st.top().second;
    }
    int top(){
        return st.top().first;
    }
};

//Optimal: improvise sc
//use a mini variable and while pushing elements, each time u get a value thats going to replace mini, use formula to update top and mini.

//tc-> O(1) for all
//sc-> O(n)

class MinStack{
    private:
        stack<int>st;
        int mini;
    public:
        void push(int value){
            if(st.empty()){
                mini=value;
                st.push(value);
                return;
            }
            if(value>mini){
                st.push(value);
            }
            else{
                st.push(2*value-mini);
                mini=value;
            }
        }
        void pop(){
            if(st.empty()) return;
            int x=st.top();
            st.pop();
            if(x<mini){
                mini=2*mini-x;
            }
        }
        int top(){
            if(st.empty()) return -1;
            int x=st.top();
            if(mini<x) return x;
            return mini;
        }
        int getMin(){
            return mini;
        }
};

int main(){
    ST s1;
    MinStack s2;
    s1.push(10);
    s1.push(20);
    s1.push(15);
    s1.push(8);
    cout<<s1.getMin()<<endl;
    s2.push(20);
    s2.push(10);
    s2.push(8);
    cout<<s2.getMin()<<endl;
    s2.pop();
    cout<<s2.getMin()<<endl;
    return 0;
}