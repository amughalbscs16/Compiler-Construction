#include <stdio.h>
#include <stdlib.h>

struct node  
{ 
  char data; 
  struct node *left; 
  struct node *right; 
};

struct node* newNode(char data) 
{ 
  // Allocate memory for new node  
  struct node* node = (struct node*)malloc(sizeof(struct node)); 
  
  // Assign data to this node 
  node->data = data; 
  
  // Initialize left and right children as NULL 
  node->left = NULL; 
  node->right = NULL; 
  return(node); 
} 

int main()
{
	char string[20] = {'a','+','b','-','d','\0'};
	int lex_beg, lex_end;
	struct node* topnode;
	struct node* presenttop;
	int count = 0;
	for (int i=0;string[i]!='\0';i++)
	{
		if (string[i] == '+' || string[i] == '-' || string[i] == '*' || string[i] == '/')
		{
			presenttop = newNode(string[i]);
			//Only the 1st time
			if (count == 0)
			{
				topnode = presenttop;
				count++;
			}
			presenttop->left = newNode(string[i-1]);
			
			presenttop = presenttop->right; 
		}
		else if (string[i+1] == '\0')
		presenttop = newNode(string[i]);
	}
	printf("%c is the Final Terminal", presenttop->data);		
	return 0;
}

