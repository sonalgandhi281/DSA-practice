#include <iostream>
using namespace std;

//Implement stack using linked list
//bcz arrays are fixed sized and thats a disadvantage, which we can overcome using LL for dynamic size.

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

class LinkedListStack{
    private:
        Node* head;
        int size;
    public:
        LinkedListStack(){
            head=NULL;
            size=0;
        }
        void push(int x){
            Node* element= new Node(x);
            element->next=head;
            head=element;
            size++;
        }
        int pop(){
            if(head==NULL){
                cout<<"Empty stack"<<endl;
                return -1;
            }
            int popped=head->val;
            Node* temp=head;
            head=head->next;
            delete temp;
            size--;
            return popped;
        }
        int top(){
            if(head==NULL){
                cout<<"Empty stack"<<endl;
                return -1;
            }
            return head->val;
        }
        bool isEmpty(){
            return (size==0);
        }
};

int main(){
    LinkedListStack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    cout<<st.top()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.isEmpty()<<endl;
    return 0;
}