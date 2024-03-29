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

///////////////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
/*
	Prime Test

	All numbers passed do not have to be positive and negatives are taken into account.
	This check will work for all values passed of the given type.
*/
bool PrimeTest(int p)
{
	// Check for negative numbers
	if (p < 0) p *= -1;

	// Major check for known prime values below 10
	if (p != 0 && p != 1 && p != 2 && p != 3 && p != 5 && p != 7)
	{
		// Minor checks using known prime numbers to get "rid" of non prime values.
		if (p % 2 == 0) return false;
		if (p % 3 == 0) return false;
		if (p % 5 == 0) return false;
		if (p % 7 == 0) return false;
	}

	return true;
}
///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
/*
	Quick Sort
*/
void QuickSort(int arr[], int left, int right)
{
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	// Partition
	while (i <= j)
	{
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;

		if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}

	// Recursion
	if (left < j) QuickSort(arr, left, j);
	if (i < right) QuickSort(arr, i, right);
}
///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
/*
	Finding if a point lies within a triangle.

	To solve for if an arbitrary point(P) lies within an arbitrary triangle(ABC),
	find the area of triangle ABC(A), if it is equal to the area of
	triangles PAB, PBC, and PAC, then P is within ABC.

	As an exercise in practice, finding a point within a polygon is given as well.
*/

float area(int x1, int y1, int x2, int y2, int x3, int y3) { return abs( (x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0 ); }

bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{
	float A = area(x1, y1, x2, y2, x3, y3);

	float A1 = area(x, y, x2, y2, x3, y3);
	float A2 = area(x1, y1, x, y, x3, y3);
	float A3 = area(x1, y1, x2, y2, x, y);

	return (A == A1 + A2 + A3);
}

bool isInsidePoly(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x, int y)
{
	if (isInside(x1, y1, x2, y2, x4, y4, x, y) == true)
		return true;
	if (isInside(x2, y2, x3, y3, x4, y4, x, y) == true)
		return true;

	return false;
}

///////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////
/*
	Bubble Sort
*/

void BubbleSort(int arr[], int left, int right)
{
	bool swapped = true;
	int temp;

	do
	{
		swapped = false;

		for (int i = left; i < right; i++)
		{
			temp = arr[i];

			if (arr[i] > arr[i + 1])
			{
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;

				swapped = true;
			}
		}
	} while (swapped == true);
}

///////////////////////////////////////////////////////////////////////////////////

int main()
{
	// Used for printing boolean values
	cout.setf(std::ios::boolalpha);

	//cout << Sum(3, 10.0, 12.0, 10.0) << endl;

	//TempConverterChallenge();

	//cout << PrimeTest(-2) << endl;

	
	int arr[] = { 1, 3, 2, 7, 10, 2, 5 };

	/*
	QuickSort(arr, 0, (sizeof(arr)/sizeof(int)) - 1);*/

	BubbleSort(arr, 0, (sizeof(arr) / sizeof(int)) - 1);

	for (int x = 0; x < (sizeof(arr) / sizeof(int)); x++)
		cout << arr[x] << endl;
	

	//cout << isInside(0, 0, 20, 0, 10, 30, 10, 15) << endl;
	//cout << isInsidePoly(0, 0, 10, 0, 10, 10, 0, 10, -1, 0) << endl;

	return EXIT_SUCCESS;
}