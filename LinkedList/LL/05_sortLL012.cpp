#include <iostream>
using namespace std;

//sort LL of 0s, 1s and 2s

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

//Brute: data replacement. use variables cnt0, cnt1, cnt2 to track occurrences of 0s, 1s and 2s while traversing the array.
//then traverse again and replace data accordingly

//tc-> O(2n), sc-> O(1)

Node* sort012LL(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* temp=head;
    int cnt0=0, cnt1=0, cnt2=0;
    while(temp!=nullptr){
        if(temp->data==0) cnt0++;
        else if(temp->data==1) cnt1++;
        else cnt2++;
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        if(cnt0){
            temp->data=0;
            cnt0--;
        }
        else if(cnt1){
            temp->data=1;
            cnt1--;
        }
        else{
            temp->data=2;
            cnt2--;
        }
        temp=temp->next;
    }
    return head;
}

//Optimal: to do this in a single traversal, we go ahead with link replacement. make three segregated lists of 0s 1s and 2s, then link between last 0 and first 1 and between last 1 and first 2.

//tc-> O(n), sc-> O(1)

Node* sort012LLOptimal(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* head0=new Node(-1);
    Node* head1=new Node(-1);
    Node* head2=new Node(-1);
    Node* zero=head0;
    Node* one=head1;
    Node* two=head2;
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data==0){
            zero->next=temp;
            zero=zero->next;
        }
        else if(temp->data==1){
            one->next=temp;
            one=one->next;
        }
        else{
            two->next=temp;
            two=two->next;
        }
        temp=temp->next;
    }
    zero->next = (head1->next) ? head1->next : head2->next;
    one->next = head2->next;
    two->next=nullptr;

    Node* newHead=head0->next;
    delete head0;
    delete head1;
    delete head2;
    return newHead;
}

int main(){
    vector<int> n1={1,0,1,2,0,1,2};
    vector<int> n2={1,0,1,2,0,1,2};
    Node* h1=convertArr2LL(n1);
    Node* h2=convertArr2LL(n2);
    Node* head1=sort012LL(h1);
    Node* head2=sort012LLOptimal(h2);
    printLL(head1);
    printLL(head2);
}