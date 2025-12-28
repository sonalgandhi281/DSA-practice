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

//Brute: i keep traversing and the moment i reach a node twice, thats my starting point.
//use hashing to remember that ive seen this node previously.
//store node, int in map

//tc-> O(nlogn), sc-> O(n)

//note i can also use set instead of map

Node* startLoop(Node* head){
    Node* temp=head;
    map<Node*,int> mp;
    while(temp){
        if(mp.find(temp)!=mp.end()){
            return temp;
        }
        mp[temp]=1;
        temp=temp->next;
    }
    return nullptr;
}

//Optimal: first detect loop using tortoise & hare algorithm. then place one pointer out of slow and fast at the head of ll. lets say slow is at head. fast is at collision point of slow & fast. move both of them by 1 step simultaneously.

//the point at which they collide again is starting point of loop.

//intuition: from head to starting point if distance is l1, then if slow is at start, fast will be at 2l1 from the head. so, slow to fast distance is also l1. lets say fast to slow dist is d. 
//fast moves closer to slow by 2 steps and slow moves away by 1 step. after each step dist reduces to d-1, and eventually to 0.

//after collision, total dist fast has covered will be 2d, slow has covered d steps.
//from start to collision, dist is d.
//i know that length of loop is l1+d.
//so, l1 is distance from collision to start of loop.

//bcz distance from start to collision is l1 and from collision to start is also l1, they will collide again at start.

//tc-> O(n), sc-> O(1)

Node* startLoopOptimal(Node* head){
    Node *slow=head, *fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return nullptr;
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

    Node* s1=startLoop(head);
    Node* s2=startLoopOptimal(head);

    cout<<s1->data<<endl;
    cout<<s2->data<<endl;
}