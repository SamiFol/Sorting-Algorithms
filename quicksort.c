#include <stdio.h>
#include <stdlib.h>

void quicksort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j) quicksort(arr, left, j);
    if (i < right) quicksort(arr, i, right);
}

int main() {
    FILE *fp;
    fp = fopen("input_100k.txt", "r");

    int num;
    int arr[1000000];
    int i = 0;

    while (fscanf(fp, "%d", &num) > 0) {
        arr[i++] = num;
    }
    fclose(fp);

    int n = i;
    quicksort(arr, 0, n - 1);
/*
fp = fopen("output.txt", "w");

    for (i = 0; i < n; i++) {
        fprintf(fp, "%d ", arr[i]);
    }
    fclose(fp);
   */
    return 0;
}
