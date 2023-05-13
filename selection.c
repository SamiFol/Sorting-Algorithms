#include <stdio.h>

void selection_sort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
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

    selection_sort(arr, n);

    printf("Sorted array: ");
   /* for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");  */

    return 0;
}

