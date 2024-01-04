#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITEMS 10000000

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(NULL));

    int* arr = (int*)malloc(NUM_ITEMS * sizeof(int));

    for (int i = 0; i < NUM_ITEMS; i++) {
        arr[i] = rand();
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();

    quickSort(arr, 0, NUM_ITEMS - 1);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f\n", cpu_time_used);
    free(arr);

    return 0;
}