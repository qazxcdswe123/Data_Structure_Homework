//
// Created by yn on 7/12/2022.
//
template<typename T>
void insertionSort(T array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        T key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

