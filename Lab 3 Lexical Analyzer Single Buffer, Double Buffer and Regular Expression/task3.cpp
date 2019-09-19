#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Words starting with T/t or M/m are:" << endl;
	string text = "Once the next lexeme is determined, forward is set to character at its right end. Then, after the lexeme is recorded as an attribute value of a token returned to the parser, Lexeme Begin is set to the character immediately after the lexeme just found. If we use the scheme of Buffer pairs we must check, each time we advance forward, that we have not moved off one of the buffers; if we do, then we must also reload the other buffer. Thus, for each character read, we make two tests: one for the end of the buffer, and one to determine what character is read (the latter may be a multiway branch). We can combine the buffer-end test with the test for the current character if we extend each buffer to hold a sentinel character at the end. The sentinel is a special character that cannot be part of the source program, and a natural choice is the character EOF.";
	int begin = 0, j;
	int forward = 0;
	for (int i=0;i<text.length();i++){
		if (text[i] == ' ')
		{
			forward=i-1;
			if (text[begin] == 't' || text[begin] == 'm' || text[begin] == 'T' || text[begin] == 'M' )
			{
				for (j=begin;j<=forward;j++)
				{
					if (((text[j] >= 'a' && text[j] <= 'z') || (text[j] >= 'A' && text[j] <= 'Z')))
					cout << text[j];
				}
				cout << "\t";
			}
			
			begin=i+1;
			forward=i+1;
				
		}
	}
	return 0;
}
