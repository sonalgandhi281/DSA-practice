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

void printLL(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

//rotate LL by k times

//traverse to find the tail, make it point to head, then traverse upto n-k th node and make it point to null and return its next element as new head by preserving it beforehand.

//for larger values of k,
//if k==multiple of length, dont change anything, return head
//otherwise do k % len rotations

//tc-> O(2n), sc-> O(1)

Node* getNthNode(Node* head, int n){
    Node* temp=head;
    int cnt=1;
    while(temp!=nullptr){
        if(cnt==n) return temp;
        cnt++;
        temp=temp->next;
    }
    return temp;
}

Node* rotateLL(Node* head, int k){
    if(head==nullptr || head->next==nullptr || k==0) return head;
    Node* tail=head;
    int len=1;
    while(tail->next!=nullptr){
        len++;
        tail=tail->next;
    }
    if(k%len==0) return head;
    k=k%len; 
    tail->next=head;
    Node* newTail=getNthNode(head,len-k);
    head=newTail->next;
    newTail->next=nullptr;
    return head;
}

int main(){
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);

    head1=rotateLL(head1,2);
    printLL(head1);
}