#include <bits/stdc++.h>
using namespace std;

class LinkedList {
public:
	// Linked list Node
	class Node {
	public:
		int data;
		Node* next;
		Node(int d)
		{
			data = d;
			next = NULL;
		}
	};

	// Head of list
	Node* head;

	// Function to delete the nth node from the end of the
	// given linked list
	Node* deleteNode(int n)
	{		
        Node* frd = head, *bkd = head;
        if(n==0 ) return head;
        
        if(!head->next && n==1) return NULL;
        int i=0 ;
        while(i!=n){
            frd = frd->next ;
            i++;
        }
        
        if(!frd) return head->next;
        while( frd->next){
            bkd = bkd->next;
            frd = frd->next;
        }
        bkd ->next = bkd->next->next;
        return head;
	}

	// Function to insert a new Node at front of the list
	Node* push(int new_data)
	{
		Node* new_node = new Node(new_data);
		new_node->next = head;
		head = new_node;
		return head;
	}

	// Function to print the linked list
	void printList()
	{
		Node* tnode = head;
		while (tnode != NULL) {
			cout << (tnode->data) << (" ");
			tnode = tnode->next;
		}
	}
};

int main()
{
	LinkedList* llist = new LinkedList();
    int n;
    cout<<"Enter the number of elements to be inserted in linkedkist"<<endl;
    cin>>n;
    cout<<"Enter the element of linked list\n";
    for(int t=0 ; t<n; t++){
        int v;
        cin>>v;
        llist->head = llist->push(v);
    }

	cout << ("Created Linked list is:\n");
	llist->printList();
    //cout<<"\nEnter the value K \n";
	int N ;
    cin>>N;
	llist->head = llist->deleteNode(N);

	cout << ("\nLinked List after Deletion is:\n");
	llist->printList();
}


