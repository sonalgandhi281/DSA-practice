#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data1, Node* next1){
            data=data1;
            next=next1;
        }
        Node(int data1){
            data=data1;
            next=nullptr;
        }
};

Node* convertArr2LL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

void printLL(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

//reverse a LL

//Brute: traverse, put all elements in stack, traverse stack and put data back
//tc-> O(2n), sc-> O(n)

Node* reverseLL(Node* head){
    stack<int> st;
    Node* temp=head;
    while(temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}

//Optimal: dont use any extra space. so, we have to change links.
//when u are on a node say temp, then we need to make temp->next point to prev and to make sure we can still go ahead, we have to store front before changing this link.

//tc-> O(n), sc-> O(1)

Node* reverseLLOptimal(Node* head){
    Node* temp=head;
    Node* prev=nullptr;
    while(temp!=nullptr){
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

//Recursive approach
Node* reverseLLRec(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    Node* newHead = reverseLLRec(head->next);
    Node* front = head->next;
    front->next=head;
    head->next=nullptr;
    return newHead;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=convertArr2LL(arr);
    head=reverseLL(head);
    printLL(head);
    head=reverseLLOptimal(head);
    printLL(head);
    head=reverseLLRec(head);
    printLL(head);
    return 0;
}