#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
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


//i have to reach node prev of middle.

//Brute: traverse entire ll, cnt length, traverse again till n/2 floor.

//tc-> O(n+n/2), sc-> O(1)

Node* deleteMiddle(Node* head){
    if(head==nullptr || head->next==nullptr) return nullptr;
    Node* temp=head;
    int cnt=0;
    while(temp){
        cnt++;
        temp=temp->next;
    }
    int prevMid=cnt/2;
    temp=head;
    while(temp){
        prevMid--;
        if(prevMid==0){
            Node* mid=temp->next;
            temp->next=temp->next->next;
            delete mid;
        }
        temp=temp->next;
    }
    return head;
}

//Optimal: using slight modifications in tortoise & hare algorithm bcz we want to reach prev node of mid.

//tc-> O(n/2), sc-> O(1)

Node* deleteMiddleOptimal(Node* head){
    if(head==nullptr || head->next==nullptr) return nullptr;
    Node *slow=head, *fast=head->next->next;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* mid=slow->next;
    slow->next=slow->next->next;
    delete mid;
    return head;
}

int main(){
    vector<int> n1={1,2,3,4,5,6};
    vector<int> n2={1,2,3,4,5};
    Node* h1=convertArr2LL(n1);
    Node* h2=convertArr2LL(n2);
    Node* ans1=deleteMiddle(h1);
    Node* ans2=deleteMiddleOptimal(h2);
    printLL(h1);
    printLL(h2);
}