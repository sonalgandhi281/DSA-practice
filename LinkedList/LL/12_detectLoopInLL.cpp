#include <iostream>
#include <map>
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

//loop in LL: if there exists a minimum of one node where you start and reach back, then LL has a loop.

//Brute: i have to use hashing to remember occurrences
//tc-> O(nlogn), sc-> O(n)

bool hasLoop(Node* head){
    Node* temp=head;
    map<Node*, int> mp;
    while(temp){
        if(mp.find(temp)!=mp.end()) return true;
        mp[temp]=1;
        temp=temp->next;
    }
    return false;
}

//Optimal: using tortoise and hare algorithm.
//slow moves 1 step, fast moves 2 steps. if slow and fast meet at some point, there is a loop.

//why will they collide: lets say distance bw fast and slow is d, since fast moves 2 steps and slow moves by 1 step, distance between fast and slow keeps decreasing bcz fast will catch up to slow bcz of cycle.
//fast moves towards slow by 2 steps, slow moves away from fast by 1 step, so d-1 reduction takes place each time and ends up reducing to 0.

//tc-> around O(n), sc-> O(1)

bool hasLoopOptimal(Node* head){
    Node *slow=head, *fast=head;
    while(fast->next!=nullptr && fast!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third;

    cout<<hasLoop(head)<<endl;
    cout<<hasLoopOptimal(head)<<endl;
}