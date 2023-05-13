#include <stdio.h>

void insertion_sort(int arr[], int n) {
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
    int i;
    FILE *file = fopen("input_100k.txt", "r");
    if (!file) {
        printf("Unable to open file\n");
        return 1;
    }

    int n = 0;
    while (fscanf(file, "%*d") == 0) {
        n++;
    }

    int arr[n];
    fseek(file, 0, SEEK_SET);
    for (i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);

    insertion_sort(arr, n);
/*    fp = fopen("output.txt", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open output file\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        fprintf(fp, "%d\n", arr[i]);
    }
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n"); */


    return 0;
}

