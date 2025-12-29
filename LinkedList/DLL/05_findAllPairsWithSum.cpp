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

//find all pairs with given sum in a SORTED DLL

//Brute: for each node temp1, keep temp2 ahead of it and traverse temp2 to check all possible pairs and their sum. the moment sum exceeds, dont check further and update temp1.

//tc-> near about O(n^2), sc-> O(1)

vector<pair<int,int>> findPairs(Node* head, int sum){
    Node* temp1=head;
    vector<pair<int,int>> ans;
    while(temp1!=nullptr){
        Node* temp2=temp1->next;
        while(temp2!=nullptr && temp1->data+temp2->data<=sum){
            if(temp1->data+temp2->data==sum){
                ans.push_back({temp1->data,temp2->data});
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return ans;
}

//Optimal: since its sorted, we take left pointer at head, and traverse and make right point at tail. add if its greater, we try to reduce by moving right towards left, if its smaller, we try to increase by moving left towards right. if same, move both.

//when they cross, (right has value less than left), we stop.

//tc-> O(2n), sc-> O(1)

vector<pair<int,int>> findPairsOptimal(Node* head, int sum){
    Node *left=head;
    Node *right=head;
    vector<pair<int,int>> ans;
    if(head==nullptr) return ans;
    while(right->next!=nullptr){
        right=right->next;
    }
    while(left->data<right->data){
        if(left->data+right->data==sum){
            ans.push_back({left->data,right->data});
            left=left->next;
            right=right->back;
        }else if(left->data+right->data<sum){
            left=left->next;
        }else{
            right=right->back;
        }
    }
    return ans;
}

int main(){
    vector<int> v={1,3,4,5,6,7,9};
    Node* head=convertArr2DLL(v);
    vector<pair<int,int>> ans1=findPairs(head,9);
    vector<pair<int,int>> ans2=findPairsOptimal(head,9);

    for(auto x: ans1){
        cout<<x.first<<" "<<x.second<<" ";
        cout<<endl;
    }
    for(auto x: ans2){
        cout<<x.first<<" "<<x.second<<" ";
        cout<<endl;
    }
}