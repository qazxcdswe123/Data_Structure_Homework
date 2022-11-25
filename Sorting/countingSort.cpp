#include <iostream>
#include <vector>

using namespace std;

// maxValue = length of arrayC
// length = size of array|output
// array = original array
// output = output array
void countingSort(int array[], int output[], int maxValue, int length)
{
	vector<int> arrayC(maxValue + 1, 0);
	for (int i = 0; i < length; i++)
	{
		arrayC[array[i]] += 1;
		// C[i] contains the number of elements equal to i
	}
	for (int i = 1; i < maxValue + 1; i++)
	{
		arrayC[i] = arrayC[i] + arrayC[i - 1];
		// C[i] contains the number of elements less than or equal to i
	}
	for (int i = length - 1; i > -1; i--)
	{
		output[arrayC[array[i]] - 1] = array[i];
		arrayC[array[i]] -= 1;
	}
}

int main(void)
{
	int array[8] = {2, 5, 3, 0, 2, 3, 0, 3};
	int output[8] = {0};
	int maxValue = 5;
	int length = 8;
	countingSort(array, output, maxValue, length);
	for (int i = 0; i < length; i++)
	{
		cout << output[i] << " ";
	}
}
