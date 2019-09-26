#include <stdio.h>
#include <stdlib.h>
/*Flex for counting the digits/small alphabets/capital alphabets*/
int countSmallChars(char* input)
{
	int tempcount = 0,i;
	for (i=0;input[i]!='\0';i++)
	{
		if (input[i]>='a' && input[i]<='z')
		tempcount++;
	}
	return tempcount;
}
int countCapitalChars(char* input)
{
	int tempcount = 0,i;
	for (i=0;input[i]!='\0';i++)
	{
		if (input[i]>='A' && input[i]<='Z')
		tempcount++;
	}
	return tempcount;
}
int countDigits(char* input)
{
	int tempcount = 0,i;
	for (i=0;input[i]!='\0';i++)
	{
		if (input[i]>='0' && input[i]<='9')
		tempcount++;
	}
	return tempcount;
}
int main()
{
	char input[30];
	int noSAlpha,noCAlpha,noDigits;
	printf("Enter a string: ");
	scanf(" %s", input);
	noSAlpha = countSmallChars(input);
	noCAlpha = countCapitalChars(input);
	noDigits = countDigits(input);
	printf("Number of \nDigits: %d\nSmall Letters: %d\nCapital Letters: %d\n\n", noDigits, noSAlpha, noCAlpha);
	return 0;
}
