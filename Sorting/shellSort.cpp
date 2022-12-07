//
// Created by yn on 7/12/2022.
//
template<typename T>
void shellSort(T array[], int size)
{
    int gap = size / 2;
    while (gap > 0)
    {
        for (int i = gap; i < size; i++)
        {
            T temp = array[i];
            int j = i;
            while (j >= gap && array[j - gap] > temp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = temp;
        }
        gap /= 2;
    }
}
