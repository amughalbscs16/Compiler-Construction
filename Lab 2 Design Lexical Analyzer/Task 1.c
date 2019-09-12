#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool isOperator(char opr);
int main()
{
	char opr;
	printf("Enter any operator: ");
	scanf("%c",&opr);
	bool result = isOperator(opr);
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
