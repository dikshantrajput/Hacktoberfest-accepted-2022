#include <iostream>
using namespace std;

class node
{
public:
  int data;
  node *next;
  node(int val)
  {
    data = val;
    next = NULL;
  }
};

void deletionatHead(node *&head)
{
  node *dte = head;
  head = head->next;
  delete dte;
}

void deletion(node *&head, int val)
{
  node *temp = head;
  while (temp->next->data != val)
  {
    temp = temp->next;
  }
  node *dte = temp->next;
  temp->next = temp->next->next;
  delete dte;
  cout << endl;
}

node *reverseUsingItteration(node *head)
{
  node *pre;
  node *curr;
  node *nxt;

  pre = NULL;
  curr = head;
  nxt = head->next;

  while (curr != NULL)
  {
    nxt = curr->next;
    curr->next = pre;
    pre = curr;
    curr = nxt;
  }
  return pre;
}

node *reverseUsingReccursion(node *&head)
{
  node *newhead = reverseUsingReccursion(head->next);
  newhead->next = head;
  head->next = NULL;
  return newhead;
}

node *reversekNode(node *head, int k)
{
  node *pre = NULL;
  node *curr = head;
  node *nxt;
  int count = 0;

  while (count < k && curr != NULL)
  {
    nxt = curr->next;
    curr->next = pre;
    pre = curr;
    curr = nxt;
    count++;
  }

  if (nxt != NULL)
  {
    head->next = reversekNode(nxt, k);
  }
  return pre;
}

bool floydsCycleDetection(node *head)
{
  node *fast = head;
  node *slow = head;

  while (fast!=NULL && fast->next!=NULL)
  {
    fast = fast->next->next;
    slow = slow->next;
    if (fast == slow)
    {
      return true;
    }
  }
    return false;
}

void appendAtLast(node *&head,int val)
{
  node *newnode = new node(val);
  node *temp = head;
  if (head == NULL)
  {
    head = newnode;
    return;
  }
  else
  {
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newnode;
  }
}

void display(node *head)
{
  node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << "-";
    temp = temp->next;
  }
}

int length(node* head){
  node* temp = head;
  int count=0;
  while(temp->next != NULL){
    temp=temp->next;
    count++;
  }
  return count;
}

void appendAtLast(node* &head,int k){
  int len = length(head);
  node* temp = head;
  int count=1;
  while(count < k){
    temp=temp->next;
    count++;
  }
  node* newHead = temp->next;
  node* newTail = temp;
}

node* evenafterodd(node* head){
  node* even=head->next;
  node* odd=head;
  node* evenHead = head->next;
  while(even->next != NULL && odd->next != NULL){
    odd->next=even->next;
    odd=odd->next;
    even->next=odd->next;
    even=even->next;
  }

  odd->next=evenHead;
  if(odd->next != NULL){
    even->next=NULL;
  }
  return head;
}

int main()
{
  node* head = NULL;
  appendAtLast(head,1);
  appendAtLast(head,2);
  appendAtLast(head,3);
  appendAtLast(head,4);
  appendAtLast(head,5);
  appendAtLast(head,6);
  appendAtLast(head,7);
  display(head);
  cout<<endl;
  node* newHead = evenafterodd(head);
  display(newHead);
  return 0;
}