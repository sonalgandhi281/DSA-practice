#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;

    Node(int data1, Node *next1, Node *child1)
    {
        data = data1;
        next = next1;
        child=child1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        child=nullptr;
    }
};

void printLLVertical(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->child;
    }
    cout<<endl;
}

//each node in ll has child ll in sorted order.
//we have to flatten all these in sorted order in the form of a vertical ll.

//Brute: traverse and for each node traverse in bottom direction as well, take all integers, put them into an array, sort the array, convert it into a vertical ll.

//tc-> O(n*m + nmlognm + n*m) = O(2*n*m + nmlognm)
//sc-> O(2*n*m)

Node* convertVertical(vector<int> &arr){
    if(arr.size()==0) return nullptr;
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode=new Node(arr[i]);
        temp->child=newNode;
        temp=temp->child;
    }
    return head;
}

Node* flattenLL(Node* head){
    vector<int> arr;
    Node* temp=head;
    while(temp!=nullptr){
        Node* t2=temp;
        while(t2!=nullptr){
            arr.push_back(t2->data);
            t2=t2->child;
        }
        temp=temp->next;
    }
    sort(arr.begin(),arr.end());
    head=convertVertical(arr);
    return head;
}

//Optimal: use the fact that vertical LLs are sorted. also, do in place instead of creating new vertical LL.
//use merge 2 sorted list approach recursively
//by recursion and backtracking

//tc-> O(n*(2m)), sc-> O(n) recursive stack space

Node* merge2lists(Node* list1, Node* list2){
    Node* dummyNode = new Node(-1);
    Node* res=dummyNode;
    while(list1!=nullptr && list2!=nullptr){
        if(list1->data<list2->data){
            res->child=list1;
            res=list1;
            list1=list1->child;
        }else{
            res->child=list2;
            res=list2;
            list2=list2->child;
        }
        res->next=nullptr;
    }
    if(list1) res->child=list1;
    else res->child=list2;
    return dummyNode->child;
}

Node* flattenLLOptimal(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* mergedHead=flattenLLOptimal(head->next);
    return merge2lists(head,mergedHead);
}

int main(){
    Node* head1 = new Node(5);
    head1->child = new Node(14);

    head1->next = new Node(10);
    head1->next->child = new Node(15);

    head1->next->next = new Node(12);
    head1->next->next->child = new Node(13);
    head1->next->next->child->child = new Node(20);

    head1->next->next->next = new Node(7);
    head1->next->next->next->child = new Node(17);

    head1=flattenLL(head1);
    printLLVertical(head1);

    Node* head2 = new Node(5);
    head2->child = new Node(14);

    head2->next = new Node(10);
    head2->next->child = new Node(15);

    head2->next->next = new Node(12);
    head2->next->next->child = new Node(13);
    head2->next->next->child->child = new Node(20);

    head2->next->next->next = new Node(7);
    head2->next->next->next->child = new Node(17);

    head2=flattenLLOptimal(head2);
    printLLVertical(head2);
}