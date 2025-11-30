#include <iostream>
using namespace std;

//Implement queue using array
//tc-> O(1) for all operations
//sc-> O(n) size of array

class ArrayQueue{
    private:
        int* arrQueue;
        int capacity;
        int currSize;
        int start, end;
    public:
        ArrayQueue(int size=10){
            capacity=size;
            arrQueue=new int[capacity];
            start=-1, end=-1;
            currSize=0;
        }
        ~ArrayQueue(){
            delete[] arrQueue;
        }
        void push(int x){
            if(currSize==capacity){
                cout<<"Queue is full"<<endl;
                return;
            }
            if(end==-1){
                start=0, end=0;
            }
            else{
                end=(end+1)%capacity;
            }
            arrQueue[end]=x;
            currSize++;
        }
        int pop(){
            if(isEmpty()){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            int popped=arrQueue[start];
            if(currSize==1){
                start=-1, end=-1;
            }
            else{
                start=(start+1)%capacity;
            }
            currSize--;
            return popped;
        }
        int peek(){
            if(start==-1){
                cout<<"Queue is empty"<<endl; //or use isEmpty()
                return -1;
            }
            return arrQueue[start];
        }
        int queueSize(){
            return currSize;
        }
        bool isEmpty(){
            return (currSize==0);
        }
};

int main(){
    ArrayQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.peek()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.peek()<<endl;
    cout<<q.queueSize()<<endl;
    cout<<q.isEmpty()<<endl;
    return 0;
}