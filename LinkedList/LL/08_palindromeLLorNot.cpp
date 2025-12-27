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

//Brute: traverse LL and put elements in stack. then traverse again and compare with top of stack. if matches, pop and continue. if stack becomes empty or traversal reaches null, its palindrome.

//tc-> O(2n), sc-> O(n)

bool isPalindrome(Node* head){
    stack<int> st;
    Node* temp=head;
    while(temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        if(temp->data!=st.top()){
            return false;
        }
        temp=temp->next;
        st.pop();
    }
    return true;
}

//Optimize: without extra space. 
//i need to match 1st half and 2nd half. but links are forward so i cant traverse back. i need to change the links of 2nd half and reverse them. but first i have to find middle (use tortoise & hare method).

//slow moves 1 step fast moves 2 steps. stop fast at 2nd last(even ll) or at last(odd ll). then slow will be at m1 middle (even length LL). then reverse 2nd half. then take 2 pointers to compare both halves.

//tc-> O(n/2+n/2+n/2+n/2)=O(2n), sc-> O(1)

Node* reverseLL(Node* head){
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

bool isPalindromeOptimal(Node* head){
    if(head==nullptr || head->next==nullptr) return true;
    Node* slow=head;
    Node* fast=head;
    while(fast->next->next!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newHead=reverseLL(slow->next);
    Node* first=head;
    Node* second=newHead;
    while(second!=nullptr){
        if(first->data!=second->data){
            reverseLL(newHead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverseLL(newHead);
    return true;
}

int main(){
    vector<int> arr={1,2,3,3,2,1};
    Node* head=convertArr2LL(arr);
    printLL(head);
    cout<<isPalindrome(head)<<endl;
    cout<<isPalindromeOptimal(head)<<endl;
    return 0;
}