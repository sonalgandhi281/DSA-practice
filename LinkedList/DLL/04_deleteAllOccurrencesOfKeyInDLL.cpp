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

//just traverse and change links if key is found and free that node.
//tc-> O(n), sc-> O(1)

Node* deleteAllKey(Node* head, int key){
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data==key){
            if(temp==head){
                head=head->next;
            }
            Node* nextNode=temp->next;
            Node* prevNode=temp->back;
            if(nextNode) nextNode->back=prevNode;
            if(prevNode) prevNode->next=nextNode;
            free(temp);
            temp=nextNode;
        }else{
            temp=temp->next;
        }
    }
    return head;
}

int main(){
    vector<int> v={10,2,5,1,10,8,4,10};
    Node* head=convertArr2DLL(v);
    printDLL(head);
    head=deleteAllKey(head,10);
    printDLL(head);
}