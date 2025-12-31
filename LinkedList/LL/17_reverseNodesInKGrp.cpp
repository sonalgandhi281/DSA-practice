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

//figure out all groups of size k and individually reverse these groups.

//we break out group into individual LLs and reverse.

//tc-> O(2n), sc-> O(1)

Node* getKthNode(Node* temp, int k){
    k--;
    while(temp!=nullptr && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
}

void reverseLL(Node* head){
    Node* prev=nullptr;
    Node* temp=head;
    while(temp!=nullptr){
        Node* nextNode=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nextNode;
    }
}

Node* reverseGroup(Node* head, int k){
    Node* temp=head;
    Node* prevNode=nullptr;
    while(temp!=nullptr){
        Node* kthNode=getKthNode(temp, k);
        if(kthNode==nullptr){
            if(prevNode) prevNode->next=temp;
            break;
        }
        Node* nextNode=kthNode->next;
        kthNode->next=nullptr;
        reverseLL(temp);
        if(temp==head){
            head=kthNode;
        }else{
            prevNode->next=kthNode;
        }
        prevNode=temp;
        temp=nextNode;
    }
    return head;
}

int main(){
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);

    head1=reverseGroup(head1,2);
    printLL(head1);
}