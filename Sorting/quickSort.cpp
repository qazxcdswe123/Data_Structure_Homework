//
// Created by yn on 7/12/2022.
//
#include <algorithm>

template<typename T>
void dualPivotQuickSort(T array[], int left, int right) {
    if (left < right) {
        if (array[left] > array[right]) {
            std::swap(array[left], array[right]);
        }

        T pivot1 = array[left];
        T pivot2 = array[right];
        int less = left + 1;
        int great = right - 1;

        for (int k = less; k <= great; k++) {
            if (array[k] < pivot1) {
                std::swap(array[k], array[less++]);
            } else if (array[k] > pivot2) {
                while (k < great && array[great] > pivot2) {
                    great--;
                }
                std::swap(array[k], array[great--]);

                if (array[k] < pivot1) {
                    std::swap(array[k], array[less++]);
                }
            }
        }

        int dist = great - less;

        if (dist < 13) {
            for (int k = less; k <= great; k++) {
                for (int m = k; m > less && array[m] < array[m - 1]; m--) {
                    std::swap(array[m], array[m - 1]);
                }
            }
        } else {
            std::swap(array[less - 1], array[left]);
            std::swap(array[great + 1], array[right]);
            dualPivotQuickSort(array, left, less - 2);
            dualPivotQuickSort(array, great + 2, right);

            if (pivot1 < pivot2) {
                dualPivotQuickSort(array, less, great);
            }
        }
    }
}

template<typename T>
void quickSort(T array[], int left, int right) {
    int i = left;
    int j = right;
    T pivot = array[(left + right) / 2];

    while (i <= j) {
        while (array[i] < pivot) {
            i++;
        }

        while (array[j] > pivot) {
            j--;
        }

        if (i <= j) {
            std::swap(array[i], array[j]);
            i++;
            j--;
        }
    }

    if (left < j) {
        quickSort(array, left, j);
    }

    if (i < right) {
        quickSort(array, i, right);
    }
}
