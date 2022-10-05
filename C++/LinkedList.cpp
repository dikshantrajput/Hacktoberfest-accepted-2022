// the functions names are self explainatory

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int d){
        data =d;
        next = NULL;
    }
};

// insertion at head
void insertAtHead(Node *&head,int d){
    Node* newNode = new Node(d);
    newNode->next = head;
    head = newNode;
}

void print(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

void insertAtEnd(Node*&head,int d){
    Node*newNode = new Node(d);
    Node*temp=head;
    while(temp -> next!=NULL)   // to reach the end that is NULL
    {
        temp = temp-> next;
    }
    temp->next = newNode;
}

void insertAtPos(Node *&head,int d,int p){
    if(p==1){
        insertAtHead(head,d);
        return;
    }
    Node*newNode = new Node(d);
    Node*temp = head;
    while(p-1 > 1){
        temp = temp->next;
        p--;
    }
    Node *save=temp->next;
    temp->next = newNode;
    newNode->next=save;
    save =0;
    delete save;
}

void deletionAtHead(Node *&head){
    if(head == NULL)
        return;
    Node*temp = head;
    head=  head->next;
    delete temp;
}

void deleteAtEnd(Node*&head){
    if(head == NULL){
        return;
    }
    if(head->next == NULL){
        deletionAtHead(head);
        return;
    }
    Node*temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next =NULL;
}

int main(){
    
    Node*head = NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtEnd(head,6);
    insertAtPos(head,9,4);
    insertAtPos(head,10,1);
    print(head);

return 0;
}
