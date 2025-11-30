#include <iostream>
using namespace std;

//Implement queue using linked list
//tc-> O(1) for all operations
//sc-> O(no. of elements)

struct Node{
    int val;
    Node* next;
    Node(int d){
        val=d;
        next=NULL;
    }
};

class LinkedListQueue{
    private:
        Node* start;
        Node* end;
        int size;
    public:
        LinkedListQueue(){
            start=NULL, end=NULL;
            size=0;
        }
        void push(int x){
            Node* element=new Node(x);
            if(end==NULL){
                end=element;
                start=element;
            }else{
                end->next=element;
                end=element;
            }
            size++;
        }
        int pop(){
            if(start==NULL){
                cout<<"Empty queue"<<endl;
                return -1;
            }
            int popped=start->val;
            Node* temp=start;
            start=start->next;
            delete temp;
            size--;
            return popped;
        }
        int peek(){
            if(start==NULL){
                cout<<"Empty queue"<<endl;
                return -1;
            }
            return start->val;
        }
        bool isEmpty(){
            return (size==0);
        }
};

int main(){
    LinkedListQueue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout<<q.peek()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.isEmpty()<<endl;
    return 0;
}