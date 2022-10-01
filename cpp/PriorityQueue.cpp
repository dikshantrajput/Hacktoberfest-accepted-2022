## C++ program to implement Priority Queue
 
**Using Arrays**
 
#include <bits/stdc++.h>
using namespace std;

// Structure for the elements in the
// priority queue
struct item {
	int value;
	int priority;
};

// Store the element of a priority queue
item pr[100000];

// Pointer to the last index
int size = -1;

// Function to insert a new element
// into priority queue
void enqueue(int value, int priority)
{
	// Increase the size
	size++;

	// Insert the element
	pr[size].value = value;
	pr[size].priority = priority;
}

// Function to check the top element
int peek()
{
	int highestPriority = INT_MIN;
	int ind = -1;

	// Check for the element with
	// highest priority
	for (int i = 0; i <= size; i++) {

		// If priority is same choose
		// the element with the
		// highest value
		if (highestPriority == pr[i].priority && ind > -1
			&& pr[ind].value < pr[i].value) {
			highestPriority = pr[i].priority;
			ind = i;
		}
		else if (highestPriority < pr[i].priority) {
			highestPriority = pr[i].priority;
			ind = i;
		}
	}

	// Return position of the element
	return ind;
}

// Function to remove the element with
// the highest priority
void dequeue()
{
	// Find the position of the element
	// with highest priority
	int ind = peek();

	// Shift the element one index before
	// from the position of the element
	// with highest priority is found
	for (int i = ind; i < size; i++) {
		pr[i] = pr[i + 1];
	}

	// Decrease the size of the
	// priority queue by one
	size--;
}

// Driver Code
int main()
{
	// Function Call to insert elements
	// as per the priority
	enqueue(10, 2);
	enqueue(14, 4);
	enqueue(16, 4);
	enqueue(12, 3);

	// Stores the top element
	// at the moment
	int ind = peek();

	cout << pr[ind].value << endl;

	// Dequeue the top element
	dequeue();

	// Check the top element
	ind = peek();
	cout << pr[ind].value << endl;

	// Dequeue the top element
	dequeue();

	// Check the top element
	ind = peek();
	cout << pr[ind].value << endl;

	return 0;
}


**Using LinkedList**



#include <bits/stdc++.h>
using namespace std;

// Node
typedef struct node {
	int data;

	// Lower values indicate
	// higher priority
	int priority;

	struct node* next;

} Node;

// Function to create a new node
Node* newNode(int d, int p)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = d;
	temp->priority = p;
	temp->next = NULL;

	return temp;
}

// Return the value at head
int peek(Node** head) { return (*head)->data; }

// Removes the element with the
// highest priority form the list
void pop(Node** head)
{
	Node* temp = *head;
	(*head) = (*head)->next;
	free(temp);
}

// Function to push according to priority
void push(Node** head, int d, int p)
{
	Node* start = (*head);

	// Create new Node
	Node* temp = newNode(d, p);

	// Special Case: The head of list has
	// lesser priority than new node
	if ((*head)->priority < p) {

		// Insert New Node before head
		temp->next = *head;
		(*head) = temp;
	}
	else {

		// Traverse the list and find a
		// position to insert new node
		while (start->next != NULL
			&& start->next->priority > p) {
			start = start->next;
		}

		// Either at the ends of the list
		// or at required position
		temp->next = start->next;
		start->next = temp;
	}
}

// Function to check is list is empty
int isEmpty(Node** head) { return (*head) == NULL; }

// Driver code
int main()
{

	// Create a Priority Queue
	// 7->4->5->6
	Node* pq = newNode(4, 1);
	push(&pq, 5, 2);
	push(&pq, 6, 3);
	push(&pq, 7, 0);

	while (!isEmpty(&pq)) {
		cout << " " << peek(&pq);
		pop(&pq);
	}
	return 0;
}
