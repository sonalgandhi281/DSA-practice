#include <iostream>
using namespace std;

//group odd index nodes together and even index nodes together in a given LL

//eg: 1->3->4->2->5->6 will become 1->4->5->3->2->6

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


//Brute: rearrange data. traverse the LL and get odd index data, put into a list, then traverse even indexes, put data into list. traverse list, update LL data.

//tc-> O(2n), sc-> O(n)

Node* oddEven(Node* head){
    if(head==NULL || head->next==NULL) return head;
    vector<int> v;
    Node* temp=head;
    while(temp && temp->next){
        v.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp) v.push_back(temp->data);
    temp=head->next;
    while(temp && temp->next){
        v.push_back(temp->data);
        temp=temp->next->next;
    }
    if(temp) v.push_back(temp->data);
    temp=head;
    int i=0;
    while(temp!=nullptr){
        temp->data=v[i];
        i++;
        temp=temp->next;
    }
    return head;
}

//Optimal: optimize sc. dont use any external ds. we change links. first change links for odd index nodes, then for even index nodes. then last odd should point to first even.

//tc-> O(n/2)*2 bcz of 2 operations being done = O(n), sc-> O(1)

Node* oddEvenOptimal(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* odd=head;
    Node* even=head->next;
    Node* evenHead=head->next;
    while(even!=nullptr && even->next!=nullptr){
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=evenHead;
    return head;
}

int main(){
    vector<int> n1={2,4,3,1,7,8};
    vector<int> n2={5,6,4,10,2};
    Node* h1=convertArr2LL(n1);
    Node* h2=convertArr2LL(n2);
    Node* head1=oddEven(h1);
    Node* head2=oddEvenOptimal(h2);
    printLL(head1);
    printLL(head2);
}