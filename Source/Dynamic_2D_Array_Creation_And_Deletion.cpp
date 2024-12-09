#include <iostream>

int main()
{
	// 2 * 3 matrix
	int rows = 4;
	int columns = 6;
	int** array = new int* [rows]; // creation of rows
	for (int i = 0; i < rows; ++i)
	{
		array[i] = new int[columns]; // creation of columns
	}

	// Assiging the values to 2D array
	static int val = 0;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			array[i][j] = val;
			val++;
		}
	}

	// Printing the values in 2D array
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
		{
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}

	// Deleting 2D array
	for (int i = 0; i < rows; i++)
	{
		delete [] array[i]; // clearing the individual rows (i.e. sub array)
	}
	delete[] array; // deleting the array of pointers
	array = nullptr;

	return 0;
}

//Output
/*
0 1 2 3 4 5
6 7 8 9 10 11
12 13 14 15 16 17
18 19 20 21 22 23
*/