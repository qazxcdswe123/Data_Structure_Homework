// use counting sort to sort an array of integers

#include <iostream>
#include <vector>

using namespace std;

void counting_sort(vector<int> &arr, int k) {
	vector<int> count(k + 1, 0);
	vector<int> output(arr.size(), 0);
	for (int i = 0; i < arr.size(); i++) {
		count[arr[i]]++;
	}
	for (int i = 1; i <= k; i++) {
		count[i] += count[i - 1];
	}
	for (int i = arr.size() - 1; i >= 0; i--) {
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	for (int i = 0; i < arr.size(); i++) {
		cout << output[i] << " ";
	}
	cout << endl;

}

int main(void)
{
	vector<int> arr = {5, 4, 3, 2, 1};
	counting_sort(arr, 5);
	return 0;
}
