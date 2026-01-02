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

void printLL(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
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

//Brute: traverse all lists and put all elements in an array. sort the array. convert it to LL.

//tc-> O(kn + knlogkn + kn)
//sc-> O(2kn )

Node* mergeLists(vector<Node*> heads){
    vector<int> arr;
    for(int i=0;i<heads.size();i++){
        Node* temp=heads[i];
        while(temp!=nullptr){
            arr.push_back(temp->data);
            temp=temp->next;
        }
    }
    sort(arr.begin(),arr.end());
    Node* head=convertArr2LL(arr);
    return head;
}

//Better: using merge 2 sorted lists recursively.

//tc-> O(n*(k*(k+1))/2) around n^3
//sc-> O(1)

Node* merge2lists(Node* list1, Node* list2){
    Node* dummyNode=new Node(-1);
    Node* res=dummyNode;
    while(list1!=nullptr && list2!=nullptr){
        if(list1->data<list2->data){
            res->next=list1;
            res=list1;
            list1=list1->next;
        }else{
            res->next=list2;
            res=list2;
            list2=list2->next;
        }
        res->next=nullptr;
    }
    if(list1) res->next=list1;
    else res->next=list2;
    return dummyNode->next;
}

Node* mergeListsBetter(vector<Node*> heads){
    Node* head=heads[0];
    for(int i=1;i<heads.size();i++){
        head=merge2lists(head,heads[i]);
    }
    return head;
}

//Optimal: using min-heap (a ds that returns min value) (priority queue in c++ implements min-heap)

//tc-> O(klogk + knlogk), sc-> O(k)

Node* mergeListsOptimal(vector<Node*> heads){
    priority_queue<
        pair<int,Node*>,
        vector<pair<int,Node*>>,
        greater<pair<int,Node*>>
    > pq;
    for(int i=0;i<heads.size();i++){
        if(heads[i]!=nullptr){
            pq.push({heads[i]->data,heads[i]});
        }
    }
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode;
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        if(it.second->next){
            pq.push({it.second->next->data,it.second->next});
        }
        temp->next=it.second;
        temp=temp->next;
    }
    return dummyNode->next;
}

int main(){
    vector<int> arr1 = {1, 4, 5};
    vector<int> arr2 = {1, 3, 4};
    vector<int> arr3 = {2, 6};

    vector<Node*> heads1 = {
        convertArr2LL(arr1),
        convertArr2LL(arr2),
        convertArr2LL(arr3)
    };

    Node* brute = mergeLists(heads1);
    printLL(brute);

    vector<Node*> heads2 = {
        convertArr2LL(arr1),
        convertArr2LL(arr2),
        convertArr2LL(arr3)
    };

    Node* better = mergeListsBetter(heads2);
    printLL(better);

    vector<Node*> heads3 = {
        convertArr2LL(arr1),
        convertArr2LL(arr2),
        convertArr2LL(arr3)
    };

    Node* optimal = mergeListsOptimal(heads3);
    printLL(optimal);
}