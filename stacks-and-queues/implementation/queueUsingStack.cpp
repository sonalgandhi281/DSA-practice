#include <iostream>
using namespace std;

//Implement queue using stack

//using 2 stacks (modifying push operation)
//tc-> O(2n) for push, O(1) for else
//sc-> O(no. of elements) for 2 stacks

//push: transfer all from s1 to s2, add new element to s1, transfer all from s2 to s1.
//pop, top: firectly from s1

class StackQueue{
    private:
        stack<int> s1, s2;
    public:
        void push(int x){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        int pop(){
            if(s1.empty()){
                cout<<"Empty Stack"<<endl;
                return -1;
            }
            int popped=s1.top();
            s1.pop();
            return popped;
        }
        int peek(){
            if(s1.empty()){
                cout<<"Empty Stack"<<endl;
                return -1;
            }
            return s1.top();
        }
        bool isEmpty(){
            return s1.empty();
        }
};

//if push is being used very frequently, we dont want it to be an expensive operation, like above. so, we modify pop instead of push

//tc-> O(n) for pop and peek, O(1) for else
//sc-> O(n) for elements in 2 stacks

//pop: move all from s1 to s2. this ensures reversal and now pop element from s2.

class StackQueue2{
    public:
        stack<int> s1,s2;
        void push(int x){
            s1.push(x);
        }
        int pop(){
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            if(s2.empty()){
                cout<<"Empty Queue"<<endl;
                return -1;
            }
            int popped=s2.top();
            s2.pop();
            return popped;
        }
        int peek(){
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            if(s2.empty()){
                cout<<"Empty Queue"<<endl;
                return -1;
            }
            return s2.top();
        }
        bool isEmpty(){
            return (s1.empty() && s2.empty());
        }
};

int main(){
    StackQueue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout<<q.peek()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<endl;
    StackQueue2 q2;
    q2.push(10);
    q2.push(20);
    q2.push(30);
    q2.push(40);
    q2.push(50);
    cout<<q2.peek()<<endl;
    cout<<q2.pop()<<endl;
    cout<<q2.pop()<<endl;
cout<<q2.isEmpty()<<endl;
    cout<<endl;
    return 0;
}