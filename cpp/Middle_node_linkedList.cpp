#include <iostream>

using namespace std;

class Node {
  public:
    int data; //Data to store (could be int,string,object etc)
  Node * nextElement; //Pointer to next element

  Node() {
    //Constructor to initialize nextElement of newlyCreated Node
    nextElement = nullptr;
  }
};

class LinkedList {
  private:
    Node * head;
  public:

    LinkedList();
  Node * getHead();
  bool isEmpty();
  bool printList();
  void insertAtHead(int value);
  string elements();
  void insertAtTail(int value);
  bool search(int value);
  bool deleteAtHead();
  bool Delete(int value);
  int length();
  string reverse();
  int findMid(); 
};
LinkedList::LinkedList(){
    head = nullptr;
    }
Node * LinkedList::getHead(){
return head;
}
bool LinkedList::isEmpty(){
    if(head == nullptr)
        return true;
    else
        return false;
}
bool LinkedList::printList(){
    if(isEmpty()){
        //cout << "List is Empty!";
        return false;
    }
    Node *temp = head;
    //cout <<"List : ";
    while(temp != nullptr){
        //cout<<temp->data<<"->";
        temp= temp->nextElement;
        
    }
    //cout<<"null"<<endl;
    return true;
}
void LinkedList::insertAtHead(int value){
    Node *newNode = new Node();
    newNode->data = value;
    newNode->nextElement=head;
    head = newNode;
    
}
void LinkedList::insertAtTail(int value){
    if(isEmpty()){
        insertAtHead(value);
    }
    else{
        Node *newNode = new Node();
        Node *last = head;
        while(last->nextElement != nullptr){
        last = last->nextElement;
        }
        newNode->data = value;
        
        newNode->nextElement = nullptr;
        last->nextElement = newNode;
    }
}
bool LinkedList::search(int value){
    Node *temp = head;
    while(temp != nullptr){
        if(temp->data == value){
            return true;
    }
    temp = temp->nextElement;
    }
    return false;
}
bool LinkedList::deleteAtHead(){
    if(isEmpty()){
        cout<<"List is Empty"<<endl;
        return false;
    }
    Node *currentNode = head;
    head = head->nextElement;
    delete currentNode;
    return true;
}

bool LinkedList::Delete(int value) {
        Node *currentNode = head;
        Node *previous = currentNode;
    if(isEmpty()){
        cout<<"False"<<endl;
        return false;
        } 
    if(currentNode->nextElement == NULL){
                    head = NULL;
                    delete currentNode;
                    cout<<"True";
                    return true;
                }
    if (search(value)){
        
        
        while(currentNode != nullptr){
            if(currentNode->data == value){
               
                 previous->nextElement = currentNode->nextElement;
                 delete currentNode;
                 cout<<"True";
                 return true;
            }
            previous->nextElement = currentNode->nextElement;
            currentNode = currentNode->nextElement;
        }
        }
    
    cout<<"False";
    return false;
        
}
int LinkedList::length(){
    int count = 0;
    Node *temp = head;
    while(temp != nullptr){
        count += 1;
        temp = temp->nextElement;
        }
    return count;
}
string LinkedList::elements(){
    string elementsList = "";
    Node * start = head;
    while (start != nullptr){
        elementsList += std::to_string(start->data) +"->";
        start = start->nextElement;
    }
    elementsList += "null";
    return elementsList;
}

string LinkedList::reverse() {
    Node * current = head;
    Node *prev = nullptr, *next = nullptr;
    while(current != nullptr){
        next = current->nextElement;
        current->nextElement = prev;
        prev = current;
        current = next;
    }
    head = prev;
  return elements();
}

int LinkedList::findMid() {
  int len = length();
  int mid = len/2;
  if(len %2 == 0){ mid--;}
  
  Node *temp = head;
  while(mid > 0)
  { 
        temp = temp->nextElement;
       
        mid--;
        
  }
  return temp->data;
}
int main(){
    LinkedList list;
    int num;
    for(num = 1; num<=3 ; num++) {
        list.insertAtHead(num);
        list.printList();
    }

    int mid = list.findMid();
    cout <<mid << endl;
  return 0;
}
 
