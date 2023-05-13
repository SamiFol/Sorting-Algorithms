#include <stdio.h>

void shell_sort(int arr[], int n) {
    int gap, i, j, temp;
    for (gap = n/2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    int i;
    FILE *inputFile = fopen("input_100k.txt", "r");
    if (!inputFile) {
        printf("Unable to open input file\n");
        return 1;
    }

    int n = 0;
    int temp;
    while (fscanf(inputFile, "%d", &temp) == 1) {
        n++;
    }

    int arr[n];
    fseek(inputFile, 0, SEEK_SET);
    for (i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &arr[i]);
    }

    fclose(inputFile);

    shell_sort(arr, n);

  /*  FILE *outputFile = fopen("output.txt", "w");
    if (!outputFile) {
        printf("Unable to open output file\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        fprintf(outputFile, "%d\n", arr[i]);
    }

    fclose(outputFile); */

    return 0;
}
