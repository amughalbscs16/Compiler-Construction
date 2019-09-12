#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
Author: Ali Hassaan Mughal
Task: Check if it is a valid identifier / variable.
Lab2: Compiler Construction Task 2
*/
bool isIdentifier(char identifier[]);
int main()
{
	char identifier[30];
	printf("Enter an identifier: ");
	scanf("%s", identifier);
	bool result = isIdentifier(identifier);
	return 0;
}
bool isIdentifier(char identifier[]){
	int i;
	//First - Ending Character
	if (!(identifier[i] == '_' || (identifier[i] >= 'A' && identifier[i] <= 'Z') || (identifier[i] >= 'a' && identifier[i] <= 'z')))
	{
		printf("%s: is an invalid identifier",identifier);
		return false;
	}
	//Second - Ending Character
	for (i=1;identifier[i]!='\0';i++)
	{
		if (!(identifier[i] == '_' || (identifier[i] >= 'A' && identifier[i] <= 'Z') || (identifier[i] >= 'a' && identifier[i] <= 'z') || (identifier[i] >= '0' && identifier[i] <= '9')))
		{
			printf("%s: is an invalid identifier",identifier);
			return false;
		}
	}
	printf("%s: is a valid identifier",identifier);
	return true;
}
