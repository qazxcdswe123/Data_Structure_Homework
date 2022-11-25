#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printArray(int array[], int length)
{
	for (int i = 0; i < length ; i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl;
}

void fillArray(int array[], int length)
{
	for (int i = 0; i < length ; i++)
	{
		array[i] = rand() % 1000;
	}
}

void swapElement(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
	cout << "Swapping " << *a << " and " << *b << endl;
}

void monkeySort(int array[], int length)
{
	cout << "Before ";
	printArray(array, length);

	for (int i = 0; i < length; i++)
	{
		int index = rand() % (length - i) + i;
		cout << "I = " << i << " Index = " << index << '\n';
		swapElement(&array[i], &array[index]);
	}
	cout << "After ";
	printArray(array, length);
}

int main()
{
	srand(time(0));
	int array[5] = {0};
	int length = 5;
	fillArray(array, length);

	int i = 0;
	while (i < length - 1)
	{
		if (array[i] > array[i + 1])
		{
			monkeySort(array, length);
			i = 0;
		}
		else
		{
			i++;
		}
	}
	cout << "Final\n";
	printArray(array, length);
}
