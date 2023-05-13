#include <stdio.h>
#include <stdlib.h>

int getMax(int arr[], int n) {
    int i;
    int max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    int i,exp;
    for (exp = 1; max/exp > 0; exp *= 10) {
        int output[n];
        int count[10] = {0};
        int i;

        for (i = 0; i < n; i++) {
            count[(arr[i]/exp) % 10]++;
        }

        for (i = 1; i < 10; i++) {
            count[i] += count[i-1];
        }

        for (i = n - 1; i >= 0; i--) {
            output[count[(arr[i]/exp) % 10] - 1] = arr[i];
            count[(arr[i]/exp) % 10]--;
        }

        for (i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}

int main() {
    int i;
    FILE *file;
    int n = 0;
    int arr[1000000];

    file = fopen("input.txt", "r");
    if (file) {
        while (fscanf(file, "%d", &arr[n]) != EOF) {
            n++;
        }
        fclose(file);
    } else {
        printf("Unable to open file.\n");
        return 1;
    }

    radixSort(arr, n);

 /*   for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n"); */

    return 0;
}
