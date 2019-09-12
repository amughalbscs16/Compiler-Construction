#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
Enter a string and differentiate the identifiers and operators
*/
bool isOperator(char opr);
bool isIdentifier(char identifier[]);
int main()
{
	
	return 0;
}
bool isOperator(char opr){
	switch(opr){
		case '*':
		case '-':
		case '+':
		case '/':
			printf("It is an operator");
			return true;
		default:
			printf("It is not an operator");
			return false;
	}
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
