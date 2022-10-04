#include<iostream>
#include<stdio.h>
using namespace std;

struct Node {
	int data;
	Node* next;
} *topNode = NULL;

static int sizeOfStack = 0;

bool PUSH(int value) {
	Node* newNode = new Node;

	newNode->data = value;
	newNode->next = topNode;
	topNode = newNode;

	sizeOfStack++;
	return true;
}

int POP() {
	if (topNode == NULL) {
		cout << "Sorry! Underfollow condition arised. (Stack is empty)" << endl;
		return INT_MIN;
	}

	Node* poppedNode = topNode;
	topNode = topNode->next;

	int popedItem = poppedNode->data;
	//cout << "Deleted Item = " << popedItem << endl;

	sizeOfStack--;
	return popedItem;
}

int Peek() {
	if (topNode == NULL) {
		cout << "Sorry! Stack is empty" << endl;
		return INT_MIN;
	}

	Node* peekNode = topNode;

	int peekItem = peekNode->data;
	//cout << "Peek Item = " << peekItem << endl;

	return peekItem;
}

void DISPLAY() {
	cout << "--- Items in stack as LIFO (Top/Head Node) ---" << endl;

	Node* tempNode = topNode;

	if (tempNode == NULL) {
		cout << "Sorry! Stack is empty" << endl;
		return;
	}

	while (tempNode->next != NULL) {
		cout << tempNode->data << " ";

		tempNode = tempNode->next;
	}
	cout << tempNode->data << " " << endl;
	cout << "Total Items in Stack = " << sizeOfStack << endl;
}

void displayChooseOptions() {

	cout << "\n*****MAIN MENU *****" << endl;
	cout << "1. PUSH" << endl;
	cout << "2. POP" << endl;
	cout << "3. Peek" << endl;
	cout << "4. DISPLAY" << endl;
	cout << "5. EXIT" << endl;

	cout << "\nEnter your option: ";
}

void chooseOption() {
	char choice;
	do {
		displayChooseOptions();
		cin >> choice;

		switch (choice)
		{
		case '1':
			cout << "--- PUSH item into the stack ---" << endl;
			int inputValue;
			cout << "Enter value for Push : ";
			cin >> inputValue;
			PUSH(inputValue);
			cout << "PUSH item successfully done." << endl<<endl;
			break;
		case '2':
			cout << "--- POP item from the stack ---" << endl;
			int poppedValue;
			poppedValue = POP();
			if (poppedValue != INT_MIN)
				cout << "Deleted item : " << poppedValue << endl << endl;
			break;
		case '3':
			cout << "--- PEEK item from the stack ---" << endl;
			int peekedValue;
			peekedValue = Peek();
			if (peekedValue != INT_MIN)
				cout << "Peeke item : " << peekedValue << endl << endl;
			break;
		case '4':
			DISPLAY();
			break;
		case '5':
			cout << "THANKS FOR USING THIS CONSOLE APPLICATION.\n  created by \"MD. HAMIDUR RHAMAN\"" << endl;
			return;
		default:
			cout << "Invalid Choice!";
		}
	} while (choice != '5');
}


int main()
{
	cout << "--- Welcome to console program: STACK using Linked List ---" << endl;

	chooseOption();

	return 0;
}

