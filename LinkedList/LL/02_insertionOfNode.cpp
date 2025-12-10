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

//insert at head
//tc-> O(1)
Node* insertHead(Node* head, int val){
    return new Node(val,head);
}

//insert at last
Node* insertLast(Node* head, int val){
    if(head==nullptr){
        return new Node(val);
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node* newNode= new Node(val);
    temp->next=newNode;
    return head;
}

//insert at kth element (k will be from 1 to n+1)
//traversal ko k-1 pe rok ke udhr insert krna hai
Node* insertK(Node* head, int val, int k){
    if(head==nullptr){
        if(k==1) return new Node(val);
        else return head;
    }
    if(k==1){
        Node* temp=new Node(val, head);
        return temp;
    }
    Node* temp=head;
    int cnt=0;
    while(temp){
        cnt++;
        if(cnt==k-1){
            Node* newNode=new Node(val,temp->next);
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

//insert an element before the value n
Node* insertBeforeVal(Node* head, int el, int val){
    if(head==nullptr) return nullptr;
    if(head->data==val){
        return new Node(el,head);
    }
    Node* temp=head;
    bool found=false;
    while(temp->next!=nullptr){
        if(temp->next->data==val){
            Node* newNode=new Node(el,temp->next);
            temp->next=newNode;
            found=1;
            break;
        }
        temp=temp->next;
    }
    if(found==false){
        cout<<"value not found"<<endl;
        return nullptr;
    }
    return head;
}

int main(){
    vector<int> arr={12,3,8,2};
    Node* head=convertArr2LL(arr);
    head=insertHead(head,10);
    printLL(head);
    head=insertLast(head,7);
    printLL(head);
    head=insertK(head,9,2);
    printLL(head);
    head=insertBeforeVal(head,28,8);
    printLL(head);
}