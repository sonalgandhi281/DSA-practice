#include <iostream>
using namespace std;

//doubly linked list
class Node{
    public:
        int data;
        Node* next;
        Node* back;

        Node(int data1, Node* next1, Node* back1){
            data=data1;
            next=next1;
            back=back1;
        }
        Node(int data1){
            data=data1;
            next=nullptr;
            back=nullptr;
        }
};

void printDLL(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* convertArr2DLL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

//remove duplicates from a sorted DLL

//bcz its sorted, duplicates will always be in contigous manner.

//tc-> O(n) bcz temp skipped duplicates and newNode traversed duplicates.
//sc-> O(1)

Node* removeDuplicates(Node* head){
    Node* temp=head;
    while(temp!=nullptr && temp->next!=nullptr){
        Node* nextNode=temp->next;
        while(nextNode!=nullptr && nextNode->data==temp->data){
            Node* duplicate=nextNode;
            nextNode=nextNode->next;
            free(duplicate);
        }
        temp->next=nextNode;
        if(nextNode) nextNode->back=temp;
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int> v={1,1,1,2,3,3,4,4,4,4};
    Node* head=convertArr2DLL(v);
    head=removeDuplicates(head);
    printDLL(head);
}