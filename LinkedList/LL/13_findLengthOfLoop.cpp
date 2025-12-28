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

//if no loop return 0, otherwise return length of loop

//Brute: use a map to store Node and timer. if we realise node is already there, the difference bw timers will be length

//tc-> O(n*2*logn), sc-> O(n)

int loopLength(Node* head){
    Node* temp=head;
    int timer=1;
    map<Node*, int> mp;
    while(temp){
        if(mp.find(temp)!=mp.end()){
            int value=mp[temp];
            return timer-value;
        }
        mp[temp]=timer;
        timer++;
        temp=temp->next;
    }
    return 0;
}

//Optimal: using tortoise & hare algorithm.
//first detect loop (when slow==fast), then traverse and maintain a counter, when it reaches back, that is the length

//tc-> O(n), sc-> O(1)

int findLength(Node* slow, Node* fast){
    int cnt=1;
    fast=fast->next;
    while(slow!=fast){
        cnt++;
        fast=fast->next;
    }
    return cnt;
}

int loopLengthOptimal(Node* head){
    Node *slow=head, *fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return findLength(slow, fast);
    }
    return 0;;
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

    cout<<loopLength(head)<<endl;
    cout<<loopLengthOptimal(head)<<endl;
}