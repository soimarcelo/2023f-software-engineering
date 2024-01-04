#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITEMS 10000000

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

    insertionSort(arr, NUM_ITEMS);

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f\n", cpu_time_used);
    free(arr);

    return 0;
}