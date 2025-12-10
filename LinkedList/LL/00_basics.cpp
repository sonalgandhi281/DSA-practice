#include <iostream>
using namespace std;

//creating a linked list

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

//convert array to LL
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

//find length of a LL
//tc-> O(n)
int lengthofLL(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

//search an element in LL (check if present)
int checkIfPresent(Node* head, int val){
    Node* temp=head;
    while(temp){
        if(temp->data==val) return 1;
        temp=temp->next;
    }
    return 0;
}


int main(){
    vector<int> arr={2,3,7,4};
    Node* y=new Node(arr[0]);
    cout<<y<<endl; //prints memory
    cout<<y->data<<endl; //prints data

    Node* head=convertArr2LL(arr);
    //traversal in LL [tc-> O(n)]
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    cout<<lengthofLL(head)<<endl;
    cout<<checkIfPresent(head,3)<<endl;
    cout<<checkIfPresent(head,6)<<endl;
}