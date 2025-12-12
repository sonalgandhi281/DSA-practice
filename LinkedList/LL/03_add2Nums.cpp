#include <iostream>
using namespace std;

//given two LL that represent two numbers in reversed order, return LL representing their sum in reversed order

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

void printLL(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

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

//we start adding from unit place and take carry over. since list is in reversed order of number, the head node is unit place. so keep adding and take carry over.

//we use dummy node to start to simplify implementation, otherwise we would have to handle edge cases. (whenever u need to create a new list prefer concept of dummy node)

//tc-> O(max(n1,n2)) where n1 and n2 are sizes of both LL
//sc-> O(max(n1,n2)) for returning ans

Node* add2NNum(Node* h1, Node* h2){
    Node* l1=h1;
    Node* l2=h2;
    Node* dummy=new Node(-1);
    Node* temp=dummy;
    int carry=0;
    while(l1 || l2 || carry){
        int sum=0;
        if(l1){
            sum+=l1->data;
            l1=l1->next;
        }
        if(l2){
            sum+=l2->data;
            l2=l2->next;
        }
        sum+=carry;
        carry=sum/10;
        Node* newNode=new Node(sum%10);
        temp->next=newNode;
        temp=temp->next;
    }
    return dummy->next;
}



int main(){
    vector<int> n1={2,4,3};
    vector<int> n2={5,6,4};
    Node* h1=convertArr2LL(n1);
    Node* h2=convertArr2LL(n2);
    Node* head=add2NNum(h1,h2);
    printLL(head);
}