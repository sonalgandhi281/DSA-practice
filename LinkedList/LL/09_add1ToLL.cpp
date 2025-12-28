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

//a LL is given where every node represents a digit in the number, add 1 to it and return result as a LL

//Brute: reverse LL, add 1 maintain carry, reverse LL at last to return ans
//tc-> O(3n), sc-> O(1)

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

Node* add1(Node* head){
    Node* newHead=reverseLL(head);
    int carry=1;
    Node* temp=newHead;
    while(temp!=nullptr){
        temp->data=temp->data+carry;
        if(temp->data<10){
            carry=0;
            break;
        }else{
            temp->data=0;
            carry=1;
        }
        temp=temp->next;
    }
    if(carry==1){
        Node* newNode=new Node(1);
        newHead=reverseLL(newHead);
        newNode->next=newHead;
        return newNode;
    }
    return reverseLL(newHead);
}

//Optimal: do without reversal. we cant go back because links are not in opposite dirn. so, we use recursion bcz it has backtracking.

//tc-> O(n), sc-> O(n) for recursive stack space.

int helper(Node* temp){
    if(temp==nullptr) return 1;
    int carry=helper(temp->next);
    temp->data=temp->data+carry;
    if(temp->data<10) return 0;
    temp->data=0;
    return 1;
}

Node* add1Optimal(Node* head){
    int carry=helper(head);
    if(carry==1){
        Node* newNode= new Node(1);
        newNode->next=head;
        return newNode;
    }
    return head;
}

int main(){
    vector<int> arr={9,9,9,9};
    Node* head1=convertArr2LL(arr);
    Node* head2=convertArr2LL(arr);
    Node* added=add1(head1);
    Node* added1=add1Optimal(head2);
    printLL(added);
    printLL(added1);
}