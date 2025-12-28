#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

//for odd LL, return middle.
//for even LL, we return 2nd middle.

//Brute: traverse LL, find length, ao, middle will be at n/2+1 position.

//tc-> O(n+n/2), sc-> O(1)

Node* middleLL(Node* head){
    Node* temp=head;
    int cnt=0;
    while(temp){
        cnt++;
        temp=temp->next;
    }
    int mid=cnt/2+1;
    temp=head;
    while(temp){
        mid--;
        if(mid==0) break;
        temp=temp->next;
    }
    return temp;
}

//Optimal: one pass solution.
//tortoise and hare algorithm: take slow and fast pointers. slow moves 1 step and fast moves 2 steps. 
//odd ll: when fast reaches last node, slow is pointing to middle.
//even ll: when fast reaches null, slow is pointing to middle (2nd middle).

//tc-> O(n/2), sc-> O(1)

Node* middleLLOptimal(Node* head){
    Node *slow=head, *fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main(){
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);

    Node* mid1=middleLL(head1);
    Node* mid2=middleLLOptimal(head1);
    cout<<mid1->data<<endl;
    cout<<mid2->data<<endl;
}