#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node* random;

    Node(int data1, Node *next1, Node* random1)
    {
        data = data1;
        next = next1;
        random=random1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        random=nullptr;
    }
};

void printClonedLinkedList(Node *head) {
    while (head != nullptr) {
        cout << "Data: " << head->data;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->data;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
        head = head->next;  
    }
}

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

//Brute: create all nodes first and store original and new nodes in hashmap. then traverse again and make links.

//tc-> O(2n), sc-> O(2n) for hashmap and to return the ans

Node* cloneLL(Node* head){
    Node* temp=head;
    map<Node*,Node*> mpp;
    while(temp!=nullptr){
        Node* newNode=new Node(temp->data);
        mpp[temp]=newNode;
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        Node* copyNode=mpp[temp];
        copyNode->next=mpp[temp->next];
        copyNode->random=mpp[temp->random];
        temp=temp->next;
    }
    return mpp[head];
}

//Optimal: insert copy nodes in bw instead of storing in hashmap
//insert copied node bw original nodes
//then connect random pointers
//connect next pointer

//tc-> O(3n), sc-> O(n) to return ans (to create new list)

Node* cloneLLOptimal(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        Node* copyNode=new Node(temp->data);
        copyNode->next=temp->next;
        temp->next=copyNode;
        temp=temp->next->next;
    }

    temp=head;
    while(temp!=nullptr){
        Node* copyNode=temp->next;
        if(temp->random){
            copyNode->random=temp->random->next;
        }else{
            copyNode->random=nullptr;
        }
        temp=temp->next->next;
    }

    Node* dummyNode=new Node(-1);
    Node* res=dummyNode;
    temp=head;
    while(temp!=nullptr){
        res->next=temp->next;
        res=res->next;
        temp->next=temp->next->next;
        temp=temp->next;
    }
    return dummyNode->next;
}

int main(){
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    Node* ans1=cloneLL(head);
    Node* ans2=cloneLLOptimal(head);

    printClonedLinkedList(ans1);
    printClonedLinkedList(ans2);

}