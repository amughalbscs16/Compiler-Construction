#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <map>
using namespace std;

int main()
{
	vector<string> variables;
	string tmpvar = "";
	map<char,char> schars;
	schars.insert(pair<char,char> ('+','+'));
	//Returns end of map if element does not exist, else iterator to the element;
	if (schars.end() == schars.find('+'))
	cout << "Not Found";
	
	int begin=0,forward=0,lCount=0, i,j;
	
	string buffer;
	
	ifstream file("inputexpressions.txt");
	
	if (file.is_open())
	{
		while (getline(file,buffer))
		{
			begin=0;
			forward=0;
			for (i=0;i<buffer.length();i++ )
			{
				if (buffer[i] == ' ')
				continue;
				if (buffer[i] == '=' || buffer[i] == '+' || buffer[i] == '*' || buffer[i] == '/' || buffer[i] == '-' || i == buffer.length()-1)
				{
					tmpvar="";
					schars.insert(pair<char,char>(buffer[i],buffer[i]));
					if (i>0)
					{
						forward = i-1;
						for (int j=begin; j<=forward;j++)
						{
							if (buffer[j] != ' ')
							{
							tmpvar=tmpvar+buffer[j];
							if (! ((buffer[j] >= 'a' && buffer[j] <= 'z' ) || (buffer[j] >= 'A' &&buffer[j] <= 'Z' ) || (buffer[j] >= '0' &&buffer[j] <= '9' )))
							schars.insert(pair<char,char> (buffer[j],buffer[j]));
							}
						} 
						variables.push_back(tmpvar);
					}
					forward=i+1;
					begin=i+1;
				}			
			}
			//cout << buffer << endl;
			lCount++;
		}
	}
	//cout << lCount;
	cout << "The Variables or Identifiers are: " << endl;
	
	for (int i=0;i<variables.size();i++)
	{
		cout << variables[i] << endl;
	}
	
	map<char, char>::iterator itr;
	cout << endl << endl << "Special Characters and opertors are: " ; 	
	for (itr = schars.begin(); itr != schars.end(); ++itr)
	{
		cout << itr->first << " ";
	}
	
	
	return 0;
}

