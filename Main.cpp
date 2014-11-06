#include <cstdarg>
#include <iostream>

using namespace std;

// Preprocessor Directive practice.
#define EXIT_SUCCESS 0

void PassByValue(int x)
{
	// Value of original variable does not change.
	x = 5;
}
void PassByReference(int* x)
{
	// Derefrenced pointer value changes.
	*x = 5;
}

// Fun math stuff
// num is the number of arguments
double Sum(int num, ...)
{
	// Creating variable argument list.
	va_list arguments;
	double sum = 0;

	// Get all values from arguments and add them to the list.
	va_start (arguments, num);
	for (int x = 0; x < num; x++)
		sum += va_arg (arguments, double);
	
	// End the variable list as required.
	va_end(arguments);

	return sum;
}

/*
	This is a challenge problem found on:
	- http://www.cprogramming.com/challenges/celsius_converter_table.html

	There is no source code provided and my chellenge is to convert Celsius to Fahrenheit
	in the most efficient way possible.

	I get a start value in celsius, an end value in celsius and a step size.

	The limits are: Start >= 0, end > start && end <= 50000, 0 < step <= 10
*/

inline double CToF(double amt) { return (amt * (9.0/5.0) + 32.0 ); }

void TempConverterChallenge()
{
	int lowerLimit, upperLimit, stepSize;

	// Get variables
	cout << "Please give a lower limit, limit >= 0: ";
	cin >> lowerLimit;
	cout << "\n";

	cout << "Please give an upper limit, " << lowerLimit << " > limit <= 50000: ";
	cin >> upperLimit;
	cout << "\n";

	cout << "Please give a step size, 0 < step <= 10: ";
	cin >> stepSize;
	cout << "\n\n";

	// Set up graph
	cout << "Celsius \t Fahrenheit" << endl;
	cout << "------- \t ----------" << endl;

	// Perform iterations

	for (int i = 0; i < upperLimit - lowerLimit; i += stepSize)
		cout << (lowerLimit + i) << " \t\t " << CToF(lowerLimit + i) << endl;
}

int main()
{
	cout << Sum(3, 10.0, 12.0, 10.0) << endl;

	TempConverterChallenge();

	return EXIT_SUCCESS;
}