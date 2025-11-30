#include <iostream>
using namespace std;

//Implement stack using array
//tc-> O(1) for all operations
//sc-> O(n) size of array

class ArrayStack{
    private:
        int* arrStack;
        int capacity;
        int topInd;
    public:
        ArrayStack(int size=1000){
            capacity=size;
            arrStack=new int[capacity];
            topInd=-1;
        }
        ~ArrayStack(){
            delete[] arrStack;
        }
        void push(int x){
            if(topInd>=capacity-1){
                cout<<"Stack Overflow"<<endl;
                return;
            }
            arrStack[++topInd]=x;
        }
        int pop(){
            if(isEmpty()){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            return arrStack[topInd--];
        }
        int top(){
            if(isEmpty()){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            return arrStack[topInd];
        }
        int stackSize(){
            return topInd+1;
        }
        bool isEmpty(){
            if(topInd==-1) return true;
            return false;
        }
};

int main(){
    ArrayStack st;
    st.push(5);
    st.push(3);
    st.push(2);
    cout<<st.top()<<endl;    
    st.push(1);
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.stackSize()<<endl;
    cout<<st.isEmpty()<<endl;
    return 0;
}