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

//convert array to DLL
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

//insert before head
Node* insertBeforeHead(Node* head, int val){
    Node* newHead= new Node(val,head,nullptr);
    head->back=newHead;
    return newHead;
}

//insert before tail
Node* insertBeforeTail(Node* head, int val){
    if(head->next==nullptr) return insertBeforeHead(head,val);
    Node* tail=head;
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    Node* prev=tail->back;
    Node* newNode=new Node(val,tail,prev);
    prev->next=newNode;
    tail->back=newNode;
    return head;
}

//insert before the kth element
Node* insertBeforeK(Node* head, int k, int val){
    if(k==1) return insertBeforeHead(head,val);
    Node* temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* newNode=new Node(val,temp,prev);
    prev->next=newNode;
    temp->back=newNode;
    return head;
}

//insert before a given node (node!=head)
void insertBeforeNode(Node* node, int val){
    Node* prev=node->back;
    Node* newNode=new Node(val,node,prev);
    prev->next=newNode;
    node->back=newNode;
}

int main(){
    vector<int> v={10,2,5,1};
    Node* head=convertArr2DLL(v);
    printDLL(head);
    head=insertBeforeHead(head,20);
    printDLL(head);
    head=insertBeforeTail(head,8);
    printDLL(head);
    head=insertBeforeK(head,2,12);
    printDLL(head);
    insertBeforeNode(head->next,28);
    printDLL(head);
}