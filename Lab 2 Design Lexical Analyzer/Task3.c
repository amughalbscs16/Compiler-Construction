#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
Enter a string and differentiate the identifiers and operators
*/
bool isOperator(char opr);
bool isIdentifier(char identifier[],int,int);
int main()
{

	int i,j,k,idenIndex=0,oprIndex = 0;
	bool oprAlready=false;
	char identifierList[5][20] = {"","","","",""};
	char oprList[4];
	char inputlexical[40];
	int tmplastvar=0,linescount = 1;
	printf("Enter the program: ");
	scanf("%[^\n]s", inputlexical);
	
	for (i=0;inputlexical[i]!='\0';i++)
	{
		
		if (inputlexical[i] == '\n')
		linescount++;
		if (isOperator(inputlexical[i]) || inputlexical[i] == ' ' || inputlexical[i] == '\t')
		{
			printf("operator %c \n",inputlexical[i]);
			printf("starting var: %c %c \n", inputlexical[tmplastvar], inputlexical[i-1]);
			if (isIdentifier(inputlexical,tmplastvar,i-1))
			{
				for (j=tmplastvar;j<=i-1;j++)
				{
					identifierList[idenIndex][j-tmplastvar] = inputlexical[j];
				}
				
				printf("identifier %s\n", identifierList[idenIndex]);
				idenIndex++;
			}
			tmplastvar = i+1;
			//if operator already there don't add it
			
			for (k=0;k<4;k++)
			{
				if (inputlexical[i] == oprList[i])
				{
					oprAlready=true;
				}
			}
		
			if (!oprAlready)
			{
				oprList[oprIndex] = inputlexical[i];
				oprIndex++;
				oprAlready=false;
			}
		}
		if (inputlexical[i+1] == '\0')
		{
			if (isIdentifier(inputlexical,tmplastvar,i))
			{
				for (j=tmplastvar;j<=i;j++)
				{
					identifierList[idenIndex][j-tmplastvar] = inputlexical[j];
					//printf("%d %d", j-tmplastvar, j);
				}
				
				printf("identifier %s\n", identifierList[idenIndex]);
				idenIndex++;
			}
		}
		
	}
	printf("%s\n", identifierList[2]);
	printf("%s\n", inputlexical);
	printf("The number of lines: %d", linescount);
	return 0;
}

bool isOperator(char opr){
	switch(opr){
		case '*':
		case '-':
		case '+':
		case '/':
			return true;
		default:
			return false;
	}
}

bool isIdentifier(char identifier[],int firstvar,int lastvar){
	int i;
	//First - Ending Character
	if (!(identifier[firstvar] == '_' || (identifier[firstvar] >= 'A' && identifier[firstvar] <= 'Z') || (identifier[firstvar] >= 'a' && identifier[firstvar] <= 'z')))
	{
		return false;
	}
	//Second - Ending Character
	for (i=firstvar+1;i<=lastvar;i++)
	{
		if (!(identifier[i] == '_' || (identifier[i] >= 'A' && identifier[i] <= 'Z') || (identifier[i] >= 'a' && identifier[i] <= 'z') || (identifier[i] >= '0' && identifier[i] <= '9')))
		{
			return false;
		}
	}
	return true;
}
