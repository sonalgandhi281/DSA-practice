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

//delete the head
Node* deleteHead(Node* head){
    if(head==nullptr) return head;
    Node* temp=head;
    head=head->next;
    free(temp); //or delete temp;
    return head;
}

//delete the tail 
//(stop before last element while traversing to delete)
Node* deleteTail(Node* head){
    if(head==nullptr || head->next==nullptr) return nullptr;
    Node* temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;
    return head;
}

//delete kth element of list
//if k=1, deletes head, if k=n, deletes tail, if k>n deletes nothing, and otherwise deletes kth element
Node* deleteK(Node* head, int k){
    if(head==nullptr) return head;
    if(k==1){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    int cnt=0;
    Node* temp=head;
    Node* prev=nullptr;
    while(temp!=nullptr){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

//delete value
Node* deleteElement(Node* head, int element){
    if(head==nullptr) return head;
    if(head->data==element){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node* temp=head;
    Node* prev=nullptr;
    while(temp){
        if(temp->data==element){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int> arr={12,5,3,4};
    Node* head=convertArr2LL(arr);
    head=deleteHead(head);
    printLL(head);
    head=deleteTail(head);
    printLL(head);
    head=deleteK(head,2);
    printLL(head);
    head=deleteElement(head,5);
    printLL(head);
}

