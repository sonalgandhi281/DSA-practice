#include <iostream>
using namespace std;

class Node{
    public:
        string data;
        Node* next;
        Node* back;

        Node(string data1, Node* next1, Node* back1){
            data=data1;
            next=next1;
            back=back1;
        }
        Node(string data1){
            data=data1;
            next=nullptr;
            back=nullptr;
        }
};

class Browser{
    Node* current;
    public:

    Browser(string &homepage){ //O(1)
        current=new Node(homepage);
    }

    void visit(string &url){ //O(1)
        Node* newNode=new Node(url);
        current->next=newNode;
        newNode->back=current;
        current=newNode;
    }

    string back(int steps){ //O(steps)
        while(steps){
            if(current->back) current=current->back;
            else break;
            steps--;
        }
        return current->data;
    }

    string forward(int steps){ //O(steps)
        while(steps){
            if(current->next) current=current->next;
            else break;
            steps--;
        }
        return current->data;
    }
};