// C program to demonstrate use of * for pointers in C
#include <stdio.h>

int main()
{
	// A normal integer variable
	int Var = 10;

	// A pointer variable that holds address of var.
	int *ptr = &Var;

	// This line prints value at address stored in ptr.
	// Value stored is value of variable "var"
	printf("Value of Var = %d\n", *ptr);

	// The output of this line may be different in different
	// runs even on same machine.
	printf("Address of Var = %p\n", ptr);

	// We can also use ptr as lvalue (Left hand
	// side of assignment)
	*ptr = 20; // Value at address is now 20

	// This prints 20
	printf("After doing *ptr = 20, *ptr is %d\n", *ptr);

	return 0;
}
