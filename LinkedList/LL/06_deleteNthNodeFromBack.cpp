#include <iostream>
using namespace std;

//remove the nth node from the back

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

//Brute: traverse to find length of LL. then traverse again to reach n-k node which is prev of node to be deleted and update the links and delete n-k+1 node.

//tc-> O(n)+O(n-k) = O(2n) worst case, sc-> O(1)

Node* deleteNthBack(Node* head, int n){
    Node* temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        temp=temp->next;
    }
    if(cnt==n){
        Node* newHead=head->next;
        free(head);
        return newHead;
    }
    temp=head;
    int res=cnt-n;
    while(temp!=nullptr){
        res--;
        if(res==0) break;
        temp=temp->next;
    }
    Node* deleteNode=temp->next;
    temp->next=temp->next->next;
    free(deleteNode);
    return head;
}

//Optimal: to reach the prev node of the node to be deleted, i have to traverse k steps lesser. take a fast pointer and move it k times initially, then take slow pointer and move both pointers simultaneously. 
//when fast reaches last node, slow will be pointing to prev node of node to be deleted.

//tc-> O(n), sc-> O(1)

Node* deleteNthBackOptimal(Node* head, int k){
    Node* fast=head;
    for(int i=0;i<k;i++) fast=fast->next;
    Node* slow=head;
    while(fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next;
    }
    if(fast==nullptr) return head->next;
    Node* deleteNode=slow->next;
    slow->next=slow->next->next;
    free(deleteNode);
    return head;
}

int main(){
    vector<int> n1={1,3,2,15,4,8,9};
    vector<int> n2={1,3,2,15,4,8,9};
    Node* h1=convertArr2LL(n1);
    Node* h2=convertArr2LL(n2);
    Node* head1=deleteNthBack(h1,3);
    Node* head2=deleteNthBackOptimal(h2,3);
    printLL(head1);
    printLL(head2);
}