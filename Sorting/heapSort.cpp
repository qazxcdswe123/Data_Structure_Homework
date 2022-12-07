#include <iostream>

using namespace std;

// use heap[0] as heap-size
// the length will be element + 1
// index starting from 1

template<typename T>
bool isMinHeap(T array[], int size) {
    for (int i = 0; i <= (size - 2) / 2; i++) {
        if (array[i] > array[2 * i + 1] ||
            (2 * i + 2 < size && array[i] > array[2 * i + 2])) {
            return false;
        }
    }

    return true;
}


void printArray(int array[], int length) {
    for (int i = 0; i < length; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
}

void swapElement(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
    cout << "Swapping " << *a << " and " << *b << endl;
}

void maxHeapify(int heap[], int index) {
    int left = index * 2;
    int right = index * 2 + 1;
    int largest = index;
    if (left <= heap[0] && heap[left] > heap[index]) {
        largest = left;
    }
    if (right <= heap[0] && heap[right] > heap[largest]) {
        largest = right;
    }
    if (largest != index) {
        swapElement(&heap[index], &heap[largest]);
        maxHeapify(heap, largest);
    }
}

void buildMaxHeap(int heap[]) {
    int length = sizeof(heap) / sizeof(heap[0]);
    for (int i = length / 2; i > -1; i--) {
        maxHeapify(heap, i);
    }
}

int heapMaximum(int heap[]) {
    return heap[0];
}

int main(void) {
    int heap[10] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
    buildMaxHeap(heap);
    printArray(heap, 10);
}
