#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	cout << "I can convert temperate from degrees Celcius to degrees Fahrenheight. Try me" << endl;
	cout << "Enter a temperature: ";
	double celcius;
	cin >> celcius;
	double fahren = 1.8 * celcius + 32;
	cout << fixed;
	cout << setprecision(2);
	cout << celcius << " Celcius is " << fahren << " Fahrenheit";
}
