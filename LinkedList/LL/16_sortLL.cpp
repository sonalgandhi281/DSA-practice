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

//Brute: traverse ll, put in array, sort array, reassign values to a ll.
//tc-> O(2n+nlogn), sc-> O(n)

Node* sortLL(Node* head){
    vector<int> v;
    Node* temp=head;
    while (temp)
    {
        v.push_back(temp->data);
        temp=temp->next;
    }
    sort(v.begin(),v.end());
    temp=head;
    for(int i=0;i<v.size();i++){
        temp->data=v[i];
        temp=temp->next;
    }
    return head;
}

//Optimal: modified version of merge sort.
//divide ll into halves until single nodes remain. then merge sorted halves in sorted order.

//to divide in halves, we use tortoise & hare method to find middle. 

//tc-> O(nlogn), sc-> O(1)
//or sc is O(log base 2 n) due to recursive calls

Node* middle(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    Node *slow=head, *fast=head->next;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node* mergeSorted(Node* l1, Node* l2){
    Node* dummy=new Node(-1);
    Node* temp=dummy;
    while(l1!=nullptr && l2!=nullptr){
        if(l1->data<=l2->data){
            temp->next=l1;
            l1=l1->next;
        }else{
            temp->next=l2;
            l2=l2->next;
        }
        temp=temp->next;
    }
    if(l1!=nullptr){
        temp->next=l1;
    }else{
        temp->next=l2;
    }
    return dummy->next;
}

Node* sortLLOptimal(Node* head){
    if(head==nullptr || head->next==nullptr) return head;
    Node* mid=middle(head);
    Node* right=mid->next;
    mid->next=nullptr;
    Node* left=head;
    left=sortLL(left);
    right=sortLL(right);
    return mergeSorted(left,right);
}

int main(){
    vector<int> n1={7,5,25,1,4};
    vector<int> n2={8,3,61,46,6};
    Node* h1=convertArr2LL(n1);
    Node* h2=convertArr2LL(n2);
    h1=sortLL(h1);
    h2=sortLLOptimal(h2);
    printLL(h1);
    printLL(h2);
}