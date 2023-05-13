#include <stdio.h>
#include <stdlib.h>

void counting_sort(int arr[], int n, int max) {
    int count[max + 1];
    int output[n];
    int i;
    for (i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int i,arr[1000000];
    FILE *inputFile = fopen("input.100k.txt", "r");
    if (!inputFile) {
        printf("Unable to open input file\n");
        return 1;
    }

    int n = 0, max = 0;
    while (fscanf(inputFile, "%d", &arr[n]) == 1) {
        n++;
    }

    fseek(inputFile, 0, SEEK_SET);
    for (i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &arr[i]);
    }

    fclose(inputFile);

    counting_sort(arr, n, max);

 /*   FILE *outputFile = fopen("output.txt", "w");
    if (!outputFile) {
        printf("Unable to open output file\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        fprintf(outputFile, "%d ", arr[i]);
    }

    fclose(outputFile); */

    return 0;
}
