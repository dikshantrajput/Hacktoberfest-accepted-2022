#include <iostream>
using namespace std;

// creating the linked list
class Node
{
public:
    int data;
    Node *next;
    // Node* head;

    // Instilzing the node
    Node(int data)
    {
        this->data = data;

        this->next = NULL;
    }
};
void pri_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        // cout<<"hello";
        cout << temp->data << " ";
        // cout<<"hello";

        temp = temp->next;
    }
}
//Driver code

int main()
{
    // inserting the value in node
    Node *newNode0 = new Node(10);
    Node *newNode1 = new Node(11);
    Node *newNode2 = new Node(12);
    Node *newNode3 = new Node(13);
    Node *newNode4 = new Node(14);
    // setting the linked list
    newNode0->next = newNode1;
    newNode1->next = newNode2;
    newNode2->next = newNode3;
    newNode3->next = newNode4;
    pri_list(newNode0);

    return 0;
}