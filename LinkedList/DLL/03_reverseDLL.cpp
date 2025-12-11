#include <iostream>
using namespace std;

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

//Brute:
//take a stack, use a temp node to traverse the dll and push values into the stack. then pop top element of stack and replace data in node to reverse.

//tc-> O(2n), sc-> O(n)

Node* reverseDLL(Node* head){
    Node* temp=head;
    stack<int> st;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}

//Optimal: reverse dll in a single pass
//so instead of swapping data, we should be swapping links

//tc-> O(n), sc-O(1)

Node* reverseDLLOptimal(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* temp=head;
    Node* last=nullptr;
    while(temp!=NULL){
        last=temp->back;
        temp->back=temp->next;
        temp->next=last;
        temp=temp->back;
    }
    return (last->back); //this will be new head
}

int main(){
    vector<int> v={10,2,5,1};
    Node* head=convertArr2DLL(v);
    printDLL(head);

    head=reverseDLL(head);
    printDLL(head);
    head=reverseDLLOptimal(head);
    printDLL(head);
}
