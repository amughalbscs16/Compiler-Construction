#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
//Prototypes
int pop();
void push(int);

//Variables
int top=-1;
int array[SIZE];

int main()
{
	int choice;
	int elem;
	while (1)
	{
		printf("1. Push\n2. Pop\n3. Exit\n");
		scanf(" %d", &choice);
	
		if (choice == 1)
		{
			printf("Enter element to push: ");
			scanf(" %d", &elem);
			push(elem);
		}
		else if (choice == 2)
		{
			elem = pop();
			printf("%d is the popped element\n", elem);
		}
		else if (choice == 3)
		break;
	}
	return 0;
}
int pop()
{
	if ( top >= 0 )
	{
		top -= 1;
		return array[top + 1];
	}
}
void push(int elem)
{
	if ( top < SIZE )
	{
		top++;
		array[top] = elem; 
	}
}
