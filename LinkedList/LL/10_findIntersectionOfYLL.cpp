#include <iostream>
#include <unordered_set>
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

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// given 2 LL, we have to find first common node in both LL.
// if they never collide, return NULL.

// Brute: check using nested loops.
// tc-> O(n*m), sc-> O(1)

Node *intersection(Node *head1, Node *head2)
{
    Node *temp2 = head2;
    while (temp2 != nullptr)
    {
        Node *temp1 = head1;
        while (temp1 != nullptr)
        {
            if (temp1 == temp2)
                return temp2;
            temp1 = temp1->next;
        }
        temp2 = temp2->next;
    }
    return NULL;
}

// Better: go through first LL and store all elements by hashing. then traverse 2nd LL and if a previously visited node is visited again, thats the ans.

// use a map to store Node, int.

// tc-> O(n+m), sc-> O(n)

Node *intersectionBetter(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    unordered_set<Node *> st;
    while (temp1 != nullptr)
    {
        st.insert(temp1);
        temp1 = temp1->next;
    }
    while (temp2 != nullptr)
    {
        if (st.find(temp2) != st.end())
            return temp2;
        temp2 = temp2->next;
    }
    return nullptr;
}

// Optimal: solve during traversal only. find length of both LL and find difference. then, on longer LL, move pointer by the difference steps. then, simultaneous comparison is possible.

// tc-> O(2*max(n1,n2))+O(abs(n1-n2))+O(min(n1,n2)), sc-> O(1)

Node *collisionPoint(Node *t1, Node *t2, int diff)
{
    while (diff)
    {
        diff--;
        t2 = t2->next;
    }
    while (t1 != t2)
    {
        t1 = t1->next;
        t2 = t2->next;
    }
    return t1;
}

Node *intersectionOptimal(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    int n1 = 0, n2 = 0;
    while (temp1)
    {
        n1++;
        temp1 = temp1->next;
    }
    while (temp2)
    {
        n2++;
        temp2 = temp2->next;
    }
    if (n1 < n2)
        return collisionPoint(head1, head2, n2 - n1);
    else
        return collisionPoint(head2, head1, n1 - n2);
}

// Optimized: traverse both nodes pointing to both heads, when anyone becomes null, point it to head of opposite ll and continue traversal until they collide.
// if length of both ll is same, they will just collide before reaching null.
// if they both reach last nodes at the same time, means there is no collision point.

// this algo works bcz if t2 is d steps behind, we send t1 to opp head and make it cover d steps so that both reach simultaneous traversals.

// tc-> O(n1+n2), sc-> O(1)

Node *intersectionOptimal2(Node *head1, Node *head2)
{
    if (head1 == nullptr || head2 == nullptr)
        return nullptr;
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp1 != temp2)
    { // incase both ll are same, first node itself is same
        temp1 = temp1->next;
        temp2 = temp2->next;
        if (temp1 == temp2)
            return temp1;
        if (temp1 == nullptr)
            temp1 = head2;
        if (temp2 == nullptr)
            temp2 = head1;
    }
    return temp1;
}

int main()
{
    Node *common = new Node(4);
    common->next = new Node(5);
    common->next->next = new Node(6);

    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = common;

    Node *head2 = new Node(7);
    head2->next = new Node(8);
    head2->next->next = common;

    Node *ans1 = intersection(head1, head2);
    Node *ans2 = intersectionBetter(head1, head2);
    Node *ans3 = intersectionOptimal(head1, head2);
    Node *ans4 = intersectionOptimal2(head1, head2);
    cout << ans1->data << endl;
    cout << ans2->data << endl;
    cout << ans3->data << endl;
    cout << ans4->data << endl;
}