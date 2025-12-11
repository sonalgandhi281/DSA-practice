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

//delete head
Node* deleteHead(Node* head){
    if(head==nullptr || head->next==nullptr) return nullptr;
    Node* prev=head;
    head=head->next;
    head->back=nullptr;
    prev->next=nullptr;
    free(prev);
    return head;
}

//delete tail
Node* deleteTail(Node* head){
    if(head==nullptr || head->next==nullptr) return nullptr;
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node* prev=temp->back;
    temp->back=nullptr;
    prev->next=nullptr;
    free(temp);
    return head;
}

// delete kth element
Node* deleteK(Node* head, int k){
    if(head==nullptr) return nullptr;
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* front=temp->next;
    if(prev==nullptr && front==nullptr){
        delete temp;
        return nullptr;
    }
    else if(prev==nullptr){
        return deleteHead(head);
    }
    else if(front==nullptr){
        return deleteTail(head);
    }
    prev->next=front;
    front->back=prev;
    temp->next=nullptr;
    temp->back=nullptr;
    free(temp);
    return head;
}

//delete given node of dll (node!=head)
void deleteNode(Node* temp){
    Node* prev=temp->back;
    Node* front=temp->next;
    if(front==NULL){
        prev->next=nullptr;
        temp->back=nullptr;
        free(temp);
        return;
    }
    prev->next=front;
    front->back=prev;
    temp->back=nullptr;
    temp->next=nullptr;
    free(temp);
}

int main(){
    vector<int> v={10,2,5,1,6,3};
    Node* head=convertArr2DLL(v);
    printDLL(head);
    head=deleteHead(head);
    printDLL(head);
    head=deleteTail(head);
    printDLL(head);
    head=deleteK(head,2);
    printDLL(head);
    deleteNode(head->next);
    printDLL(head);
}