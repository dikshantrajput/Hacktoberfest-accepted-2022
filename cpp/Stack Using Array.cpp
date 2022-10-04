#include<iostream>
#include<stdio.h>
using namespace std;

#define MAX_SIZE  100

int stack[MAX_SIZE];
int top = -1;

bool PUSH(int value) {

	if (top == MAX_SIZE - 1) {
		cout << "Sorry! Overfollow condition arised. (Stack is full)" << endl;
		return false;
	}

	stack[++top] = value;

	return true;
}

int POP() {
	if (top == -1) {
		cout << "Sorry! Underfollow condition arised. (Stack is empty)" << endl;
		return INT_MIN;
	}
	
	int popedItem = stack[top--];
	cout << "Deleted Item = " << popedItem << endl;
	
	return popedItem;
}

int Peek() {
	if (top == -1) {
		cout << "Sorry! Stack is empty" << endl;
		return INT_MIN;
	}
	int peekItem = stack[top];
	cout << "Peek Item = " << peekItem << endl;

	return peekItem;
}

void DISPLAY_LIFO() {
	cout << "--- Items in stack as LIFO ---" << endl;
	for (int i = top; i >= 0; i--) {
		cout << stack[i] << " ";
	}
	cout << endl;
}

void DISPLAY_FIFO() {
	cout << "--- Items in stack as FIFO ---" << endl;
	for (int i = 0; i <= top; i++) {
		cout << stack[i] << " ";
	}
	cout << endl;
}

void DISPLAY() {
	if (top == -1) {
		cout << "Sorry! Stack is empty" << endl;
		return;
	}
	char ch;
	cout << "Enter your choice for\n1. LIFO\n2. FIFO ";
	cin >> ch;
	switch (ch)
	{
	case '1':
		DISPLAY_LIFO();
		break;
	case '2':
		DISPLAY_FIFO();
		break;
	default:
		cout << "Invalid input" << endl;
		break;
	}
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
			break;
		case '2':
			cout << "--- POP item from the stack ---" << endl;
			int poppedValue;
			poppedValue = POP();
			if (poppedValue != INT_MIN)
				cout << "Deleted item : " << poppedValue << endl;
			break;
		case '3':
			cout << "--- PEEK item from the stack ---" << endl;
			int peekedValue;
			peekedValue = Peek();
			if(peekedValue != INT_MIN)
				cout << "Peeke item : " << peekedValue << endl;
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
	cout << "--- Welcome to console program: STACK using Array ---" << endl;

	chooseOption();

	return 0;
}

