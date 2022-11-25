#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void merge(vector<int> &vec, int left, int middle, int right)
{
    vector<int> leftVector;
    vector<int> rightVector;
    int leftSize = middle - left + 1;
    int rightSize = right - middle + 1;

    for (int i = 0; i < leftSize; i++)
    {
        leftVector.push_back(vec[left + i]);
    }
    for (int j = 0; j < rightSize; j++)
    {
        rightVector.push_back(vec[middle + j + 1]);
    }

    int i = 0, j = 0;
    while (i < leftSize && j < rightSize)
    {
        if (leftVector[i] < rightVector[j])
        {
            vec[left++] = leftVector[i++];
        }
        else
        {
            vec[left++] = rightVector[j++];
        }
    }
    while (i < leftSize)
    {
        vec[left++] = leftVector[i++];
    }
    while (j < rightSize)
    {
        vec[left++] = rightVector[j++];
    }
}

void Merge_Sort(vector<int> &vec, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        Merge_Sort(vec, left, middle);
        Merge_Sort(vec, middle + 1, right);
        merge(vec, left, middle, right);
    }
}

int main(void)
{
    vector<int> vec = {999, 4, 5, 2, 7, 5, 7, 11, 9, 2, 55, 242, 15, 33, 245};
    Merge_Sort(vec, 1, vec.size() - 1);
    printVector(vec);
}
