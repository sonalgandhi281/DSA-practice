#include <iostream>
using namespace std;

//Implement stack using queue.

//queue is fifo ds, so i'll have to modify it and do some extra operations such that it ends up behaving like stack(lifo)

//top() should return last entered element and pop() should delete last enetered element

//while pushing elements, pick elements before it one by one and place them ahead

//tc-> O(n) for push, O(1) for everything else
//sc-> dynamic based on no. of elements given, O(k) for storing k elements in queue

class QueueStack{
    queue<int> q;
    public:
        void push(int x){
            int s=q.size();
            q.push(x);
            for(int i=0;i<s;i++){
                q.push(q.front());
                q.pop();
            }
        }
        int pop(){
            int n=q.front();
            q.pop();
            return n;
        }
        int top(){
            return q.front();
        }
        bool isEmpty(){
            return q.empty();
        }
};

int main(){
    QueueStack st;
    st.push(5);
    st.push(3);
    st.push(2);
    cout<<st.top()<<endl;    
    st.push(1);
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.isEmpty()<<endl;
    return 0;
}