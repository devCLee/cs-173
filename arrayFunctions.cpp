//===============================================
// CS173, Spring 2025
// arrayFunctions.cpp
// This program contains functions to add together
// the elements of a 1-D array and determine
// whether the elements of an array are sorted.
//===============================================

#include <iostream>
using namespace std;

template <typename T>
void printArray(const T a[], int n);
int sumArray(const int a[], int n);
template <typename S>
bool isSorted(const S a[], int n);

const int SIZE = 5; // size of array

int main(void)
{
	int array[SIZE] = {5, 6, 7, 8, 9};
	float floatArray[SIZE] = {2.5, 9.6, 3.14, 0.3, -0.14};
	char charArray[SIZE] = {'a', 'b', 'c', 'd', 'e'};

	printArray<int>(array, SIZE);
	printArray<float>(floatArray, SIZE);
	printArray<char>(charArray, SIZE);

	// read in array values
	// for (int i = 0; i < SIZE; i++)
	//	cin >> array[i];

	// printArray(array, SIZE);

	// printFloatArray(floatArray, SIZE);

	// printCharArray(charArray, SIZE);

	cout << "sum of array values = " << sumArray(array, SIZE) << endl;

	if (isSorted<int>(array, SIZE))
		cout << "My array is sorted\n";
	else
		cout << "My array is not sorted\n";

	if (isSorted<float>(floatArray, SIZE))
		cout << "My array is sorted\n";
	else
		cout << "My array is not sorted\n";

	if (isSorted<char>(charArray, SIZE))
		cout << "My array is sorted\n";
	else
		cout << "My array is not sorted\n";

	return 0;
}

//===============================================
// printArray
// This function computes the sum of elements in
// an integer array of size n.
// PARAMETERS:
//	a	- an array of integers
//  n   - size of array (assume n >= 0)
// RETURN VALUE:
//  none, but outputs the contents of the array
//===============================================
template <typename T>
void printArray(const T a[], int n)
{

	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}

	return;
}

//===============================================
// printFloatArray
// This function computes the sum of elements in
// an float array of size n.
// PARAMETERS:
//	a	- an array of floats
//  n   - size of array (assume n >= 0)
// RETURN VALUE:
//  none, but outputs the contents of the array
//===============================================
// void printFloatArray(const float a[], int n)
//{
//
//	for (int i = 0; i < n; i++)
//	{
//		cout << a[i] << " ";
//	}
//
//	return;
//}
//
////===============================================
//// printCharArray
//// This function computes the sum of elements in
//// an char array of size n.
//// PARAMETERS:
////	a	- an array of char
////  n   - size of array (assume n >= 0)
//// RETURN VALUE:
////  none, but outputs the contents of the array
////===============================================
// void printCharArray(const char a[], int n)
//{
//
//	for (int i = 0; i < n; i++)
//	{
//		cout << a[i] << " ";
//	}
//
//	return;
// }

//===============================================
// sumArray
// This function computes the sum of elements in
// an integer array of size n.
// PARAMETERS:
//	a	- an array of integers
//  n   - size of array (assume n >= 0)
// RETURN VALUE:
//  returns sum of elements in array
//===============================================
int sumArray(const int a[], int n)
{
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}

	return sum;
}

//===============================================
// isSorted
// This function checks to see if an array is in sorted
// ascending order.
// PARAMTERS:
//	a - an array of integers
//  n - size of array with n >= 0
// RETURN VALUE:
// true if array is in sorted ascending order, false
// if not
//===============================================
// template <typename S>
// bool isSorted(const S a[], int n)
//{
//
//	bool status = true;
//
//	for (int i = 0; i < n - 1; i++)
//	{
//		if (!(a[i] < a[i + 1]))
//		{
//
//			status = false;
//
//			break;
//		}
//	}
//
//	return status;
//}

bool isSorted(int array[], int size)
{
	// If there's only one element, it's automatically sorted
	if (size == 1)
	{
		return true;
	}

	// Check each element against the next element
	for (int i = 0; i < size - 1; i++)
	{
		// If we find any element greater than the next element,
		// the array is not sorted in ascending order
		if (array[i] > array[i + 1])
		{
			return false;
		}
	}

	// If we've examined all pairs without finding any out of order,
	// then the array is sorted
	return true;
}